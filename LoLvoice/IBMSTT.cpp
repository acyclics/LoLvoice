#include "curl.h"
#include <string>
#include <iostream>
#include <winhttp.h>
#include <locale>
#include <codecvt>
#include <Windows.h>
#include <vector>
#include <mmsystem.h>
#include <fstream>
#include <sstream>
#include <time.h>
#include <thread>

#pragma comment(lib, "winmm.lib")

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
	data->append((char*)ptr, size * nmemb);
	return size * nmemb;
}

std::string loaduserpassfile();

// curl
DWORD dwError = ERROR_SUCCESS;
HINTERNET hWebSocketHandle = NULL;
BOOL fStatus = FALSE;
HINTERNET hSessionHandle = NULL;
HINTERNET hConnectionHandle = NULL;
HINTERNET hRequestHandle = NULL;
BYTE rgbCloseReasonBuffer[123];
DWORD dwCloseReasonLength = 0;
USHORT usStatus = 0;
WINHTTP_WEB_SOCKET_BUFFER_TYPE eBufferType;
INTERNET_PORT Port = INTERNET_DEFAULT_HTTPS_PORT;
std::string initmsg("{\"action\": \"start\", \"content-type\" : \"audio/l16;rate=16000\"}");
std::string closemsg("{\"action\": \"stop\"}");

// microphone (variables are global because both "readFromFirstIbm" and "setupmicrophone" uses it
HWAVEIN hWaveIn_mic;
MMRESULT result_mic;
WAVEHDR      WaveInHdr;
WAVEFORMATEX pFormat;
const int NUMPTS_mic = 16000 * 20;   // 5 seconds
short int waveInbuffer[NUMPTS_mic];   // 'short int' is a 16-bit type; I request 16-bit samples below

// ibm-tts
inline void pressEnter(INPUT ip2);
void alpaOut(char char_array[], int length);
int viewKey();
int viewOverdriveKey();
bool micState_ibm = false;
bool micClose_ibm = false;
bool inputting = true;
int keybind_ibm;
bool checkifcansilence = true;
bool checkifcansend = true;

// sets up the microphone for initiating first call to ibm. another microphone object is opened for the user to use
void setupmicrophone()
{
	// Mic
	int sampleRate = 16000;
	ZeroMemory(&pFormat, sizeof(WAVEFORMATEX));
	ZeroMemory(&WaveInHdr, sizeof(WAVEHDR));

	// Specify recording parameters
	pFormat.wFormatTag = WAVE_FORMAT_PCM;     // simple, uncompressed format
	pFormat.nChannels = 1;                    //  1=mono, 2=stereo
	pFormat.nSamplesPerSec = sampleRate;      // 44100
	pFormat.nAvgBytesPerSec = sampleRate * 2;   // = nSamplesPerSec * n.Channels * wBitsPerSample/8
	pFormat.nBlockAlign = 2;                  // = n.Channels * wBitsPerSample/8
	pFormat.wBitsPerSample = 16;              //  16 for high quality, 8 for telephone-grade
	pFormat.cbSize = 0;

	result_mic = waveInOpen(&hWaveIn_mic, WAVE_MAPPER, &pFormat,
		0L, 0L, WAVE_FORMAT_DIRECT);

	if (result_mic != MMSYSERR_NOERROR)
	{
		MessageBoxA(NULL, "Error finding audio input device", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	}

	// Set up and prepare header for input
	WaveInHdr.lpData = (LPSTR)waveInbuffer;
	WaveInHdr.dwBufferLength = NUMPTS_mic * 2;
	WaveInHdr.dwBytesRecorded = 0;
	WaveInHdr.dwUser = 0L;
	WaveInHdr.dwFlags = 0L;
	WaveInHdr.dwLoops = 0L;
	
	result_mic = waveInPrepareHeader(hWaveIn_mic, &WaveInHdr, sizeof(WAVEHDR));
	result_mic = waveInAddBuffer(hWaveIn_mic, &WaveInHdr, sizeof(WAVEHDR));
}

std::string getToken()
{
	// get username and password
	std::string pathtouserpass = loaduserpassfile();
	std::string actualuserpass;
	std::ifstream myuserpassfile(pathtouserpass);
	if (myuserpassfile.is_open())
	{
		getline(myuserpassfile, actualuserpass);
		myuserpassfile.close();
	}
	char* actualuserpassarray = new char[actualuserpass.length() / sizeof(actualuserpass[0]) + 1];
	for (int count(0); count < (actualuserpass.length() / sizeof(actualuserpass[0])); ++count)
	{
		actualuserpassarray[count] = actualuserpass[count];
	}
	actualuserpassarray[actualuserpass.length() / sizeof(actualuserpass[0])] = '\0';

	// curl
	const char IBMURL[] = "https://stream.watsonplatform.net/authorization/api/v1/token?url=https://stream.watsonplatform.net/speech-to-text/api";

	auto curl = curl_easy_init();	
	if (curl) {
		// get token
		curl_easy_setopt(curl, CURLOPT_URL, IBMURL);
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
		curl_easy_setopt(curl, CURLOPT_USERPWD, actualuserpassarray);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.60.0");
		curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
		curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

		delete[] actualuserpassarray;
		actualuserpassarray = nullptr;

		std::string header_string;
		std::string response_string;
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
		curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

		char* url_token;
		long response_code;
		double elapsed;
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
		curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
		curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url_token);

		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		curl = NULL;
	
		return response_string;
	}
}

void getIBMTTS()
{
	// use token
	std::string response_string = getToken();
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring tokenstring = converter.from_bytes(response_string);
	std::wstring token = tokenstring;
	const WCHAR *pcwszServerName = L"stream.watsonplatform.net";
	std::wstring url = L"speech-to-text/api/v1/recognize?watson-token=" + token;
	int lengthtotrans;

	// Create session, connection and request handles.
	hSessionHandle = WinHttpOpen(L"WebSocket sample",
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		NULL,
		NULL,
		0);

	hConnectionHandle = WinHttpConnect(hSessionHandle,
		pcwszServerName,
		Port,
		0);

	hRequestHandle = WinHttpOpenRequest(hConnectionHandle,
		L"GET",
		url.c_str(),
		NULL,
		NULL,
		NULL,
		WINHTTP_FLAG_SECURE);

	// Request protocol upgrade from http to websocket.
#pragma prefast(suppress:6387, "WINHTTP_OPTION_UPGRADE_TO_WEB_SOCKET does not take any arguments.")
	fStatus = WinHttpSetOption(hRequestHandle,
		WINHTTP_OPTION_UPGRADE_TO_WEB_SOCKET,
		NULL,
		0);

	// Perform websocket handshake by sending a request and receiving server's response.
	// Application may specify additional headers if needed.
	fStatus = WinHttpSendRequest(hRequestHandle,
		WINHTTP_NO_ADDITIONAL_HEADERS,
		0,
		NULL,
		0,
		0,
		0);

	fStatus = WinHttpReceiveResponse(hRequestHandle, 0);

	// Application should check what is the HTTP status code returned by the server and behave accordingly.
	// WinHttpWebSocketCompleteUpgrade will fail if the HTTP status code is different than 101.
	hWebSocketHandle = WinHttpWebSocketCompleteUpgrade(hRequestHandle, NULL);

	// The request handle is not needed anymore. From now on we will use the websocket handle.
	WinHttpCloseHandle(hRequestHandle);
	hRequestHandle = NULL;
}

void closeIBMTTS()
{
	dwError = WinHttpWebSocketClose(hWebSocketHandle,
		WINHTTP_WEB_SOCKET_SUCCESS_CLOSE_STATUS,
		NULL,
		0);

	// Check close status returned by the server.
	dwError = WinHttpWebSocketQueryCloseStatus(hWebSocketHandle,
		&usStatus,
		rgbCloseReasonBuffer,
		ARRAYSIZE(rgbCloseReasonBuffer),
		&dwCloseReasonLength);
	
	if (hRequestHandle != NULL)
	{
		WinHttpCloseHandle(hRequestHandle);
		hRequestHandle = NULL;
	}

	if (hWebSocketHandle != NULL)
	{
		WinHttpCloseHandle(hWebSocketHandle);
		hWebSocketHandle = NULL;
	}

	if (hConnectionHandle != NULL)
	{
		WinHttpCloseHandle(hConnectionHandle);
		hConnectionHandle = NULL;
	}

	if (hSessionHandle != NULL)
	{
		WinHttpCloseHandle(hSessionHandle);
		hSessionHandle = NULL;
	}
}

// sets up user's microphone, sends, and receives from ibm
void readFromIbm(char* &array, int keybind, int &sizeofbuffer)
{
	// Mic
	int sampleRate = 16000;
	short int waveInbuffer_mic[NUMPTS_mic];   // 'short int' is a 16-bit type; I request 16-bit samples below
	HWAVEIN hWaveIn_mico;
	MMRESULT result_mico;
	WAVEHDR      WaveInHdr_mic;
	WAVEFORMATEX pFormat_mic;

	ZeroMemory(&pFormat_mic, sizeof(WAVEFORMATEX));
	ZeroMemory(&WaveInHdr_mic, sizeof(WAVEHDR));

	// Specify recording parameters
	pFormat_mic.wFormatTag = WAVE_FORMAT_PCM;     // simple, uncompressed format
	pFormat_mic.nChannels = 1;                    //  1=mono, 2=stereo
	pFormat_mic.nSamplesPerSec = sampleRate;      // 44100
	pFormat_mic.nAvgBytesPerSec = sampleRate * 2;   // = nSamplesPerSec * n.Channels * wBitsPerSample/8
	pFormat_mic.nBlockAlign = 2;                  // = n.Channels * wBitsPerSample/8
	pFormat_mic.wBitsPerSample = 16;              //  16 for high quality, 8 for telephone-grade
	pFormat_mic.cbSize = 0;

	result_mico = waveInOpen(&hWaveIn_mico, WAVE_MAPPER, &pFormat_mic,
		0L, 0L, WAVE_FORMAT_DIRECT);

	if (result_mico != MMSYSERR_NOERROR)
	{
		MessageBoxA(NULL, "Error finding audio input device", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	}

	// Set up and prepare header for input
	WaveInHdr_mic.lpData = (LPSTR)waveInbuffer_mic;
	WaveInHdr_mic.dwBufferLength = NUMPTS_mic * 2;
	WaveInHdr_mic.dwBytesRecorded = 0;
	WaveInHdr_mic.dwUser = 0L;
	WaveInHdr_mic.dwFlags = 0L;
	WaveInHdr_mic.dwLoops = 0L;

	result_mico = waveInPrepareHeader(hWaveIn_mico, &WaveInHdr_mic, sizeof(WAVEHDR));
	result_mico = waveInAddBuffer(hWaveIn_mico, &WaveInHdr_mic, sizeof(WAVEHDR));

	// reset data
	BYTE rgbBuffer[1024];
	BYTE *pbCurrentBufferPointer = rgbBuffer;
	DWORD dwBufferLength = ARRAYSIZE(rgbBuffer);
	DWORD dwBytesTransferred = 0;
	sizeofbuffer = 0;
	time_t start = time(NULL);
	time_t seconds = 5; // end ibm while loop after this time has elapsed

	// read file here
	// Send and receive data on the websocket protocol.
	dwError = WinHttpWebSocketSend(hWebSocketHandle,
		WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE,
		(PVOID)initmsg.c_str(),
		initmsg.size());

	result_mico = waveInStart(hWaveIn_mico);

	while ((GetKeyState(keybind) & 0x80) != 0)
	{
		if (!((GetKeyState(keybind) & 0x80) != 0))
		{
			break;
		}
		Sleep(1);			// cheap way to lower cpu usuage
	}

	waveInStop(hWaveIn_mico);
	waveInClose(hWaveIn_mico);

	// when connection is being re-established to ibm, we pause here so the connection can be completed before we send audio data
	while (checkifcansend == false)
	{
		Sleep(1);
	}

	dwError = WinHttpWebSocketSend(hWebSocketHandle,
		WINHTTP_WEB_SOCKET_BINARY_MESSAGE_BUFFER_TYPE,
		waveInbuffer_mic,
		16000*20);

	dwError = WinHttpWebSocketSend(hWebSocketHandle,
		WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE,
		(PVOID)closemsg.c_str(),
		closemsg.size());

	start = time(NULL);
	time_t endwait = start + seconds;
	while (start < endwait)
	{
		start = time(NULL);
		dwError = WinHttpWebSocketReceive(hWebSocketHandle,
			pbCurrentBufferPointer,
			dwBufferLength,
			&dwBytesTransferred,
			&eBufferType);
		if (rgbBuffer[133] == '"')
			break;
	}

	array = new char[dwBytesTransferred / sizeof(rgbBuffer[0]) + 1];
	for (sizeofbuffer; sizeofbuffer < (dwBytesTransferred / sizeof(rgbBuffer[0])); ++sizeofbuffer)
	{
		array[sizeofbuffer] = rgbBuffer[134 + sizeofbuffer];
		if (rgbBuffer[134 + sizeofbuffer + 1] == '"')
			break;
	}
	array[sizeofbuffer + 1] = '\0';

	waveInUnprepareHeader(hWaveIn_mico, &WaveInHdr_mic, sizeof(WAVEHDR));
	ZeroMemory(&WaveInHdr_mic, sizeof(WAVEHDR));
}

// used for initiating the first call to ibm. this is required to get it working
void readFromFirstIbm(char* &array, int keybind, int &sizeofbuffer)
{
	// reset data
	BYTE rgbBuffer[1024];
	BYTE *pbCurrentBufferPointer = rgbBuffer;
	DWORD dwBufferLength = ARRAYSIZE(rgbBuffer);
	DWORD dwBytesTransferred = 0;
	sizeofbuffer = 0;

	dwError = WinHttpWebSocketSend(hWebSocketHandle,
		WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE,
		(PVOID)initmsg.c_str(),
		initmsg.size());

	result_mic = waveInStart(hWaveIn_mic);

	Sleep(1 * 1000);

	waveInStop(hWaveIn_mic);
	waveInClose(hWaveIn_mic);

	dwError = WinHttpWebSocketSend(hWebSocketHandle,
		WINHTTP_WEB_SOCKET_BINARY_MESSAGE_BUFFER_TYPE,
		waveInbuffer,
		16000 * 20);

	dwError = WinHttpWebSocketSend(hWebSocketHandle,
		WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE,
		(PVOID)closemsg.c_str(),
		closemsg.size());

	dwError = WinHttpWebSocketReceive(hWebSocketHandle,
			pbCurrentBufferPointer,
			dwBufferLength,
			&dwBytesTransferred,
			&eBufferType);
	dwError = WinHttpWebSocketReceive(hWebSocketHandle,
		pbCurrentBufferPointer,
		dwBufferLength,
		&dwBytesTransferred,
		&eBufferType);

	array = new char[dwBytesTransferred / sizeof(rgbBuffer[0]) + 1];
	for (sizeofbuffer; sizeofbuffer < (dwBytesTransferred / sizeof(rgbBuffer[0])); ++sizeofbuffer)
	{
		array[sizeofbuffer] = rgbBuffer[134 + sizeofbuffer];
		if (rgbBuffer[134 + sizeofbuffer + 1] == '"')
			break;
	}
	array[sizeofbuffer + 1] = '\0';

	waveInUnprepareHeader(hWaveIn_mic, &WaveInHdr, sizeof(WAVEHDR));
	ZeroMemory(&WaveInHdr, sizeof(WAVEHDR));
}

// ibm requires user to send noise every 30 seconds. this function reopens the connection to ibm if the user did not send audio data to ibm between 30 second intervals
void sendsilence()
{
	while (1)
	{
		Sleep(20 * 1000);

		if (checkifcansilence == true)
		{
			checkifcansend = false;
			closeIBMTTS();
			getIBMTTS();
			checkifcansend = true;
		}
		if (inputting == false)
		{
			break;
		}
	}
}

void startIbmTts()
{
	// initialize
	keybind_ibm = viewKey();
	getIBMTTS();

	INPUT ip2;
	ip2.type = INPUT_KEYBOARD;
	ip2.ki.wScan = 0;
	ip2.ki.time = 0;
	ip2.ki.dwExtraInfo = 0;
	int sizeofbuffer(0);

	// here, we initiate call to ibm using readFromFirstIbm as opposed to readFromIbm which the user uses to send voice buffer to ibm
	char * temparray = nullptr;
	setupmicrophone();
	readFromFirstIbm(temparray, keybind_ibm, sizeofbuffer);

	std::thread keepIbmAlive(sendsilence);
	while (inputting)
	{
		Sleep(1);			// cheap way of lowering cpu usage. should be fine though since user must hold keybind to get input
		if (micState_ibm == true) 
		{
			while ((GetKeyState(keybind_ibm) & 0x80) != 0) {					// when user press the keybind start input
				char * ibmarray = nullptr;
				checkifcansilence = false;
				//setupmicrophone();
				readFromIbm(ibmarray, keybind_ibm, sizeofbuffer);
				pressEnter(ip2);
				alpaOut(ibmarray, sizeofbuffer);
				Sleep(10);
				pressEnter(ip2);
				if (sizeofbuffer != 0)
				{
					delete[] ibmarray;
				}
				ibmarray = nullptr;
				checkifcansilence = true;
			}
		}
		if (micClose_ibm == true)
		{
			inputting = false;
		}
	}
	keepIbmAlive.join();
	closeIBMTTS();
}

void openIbmTts()
{
	micState_ibm = true;
}

void closeIbmtts()
{
	micState_ibm = false;
}

void endIbmstt()
{
	micClose_ibm = true;
}

void overdriveKeybind()
{
	keybind_ibm = viewOverdriveKey();
}

bool checkforhandlenull()
{
	if (hWebSocketHandle == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}