#include <iostream>
#include <Windows.h>
#include <vector>
#include <mmsystem.h>
#include <fstream>

#pragma comment(lib, "winmm.lib")

short int waveIn[44100 * 20];	 // should match NUMPTS
const int NUMPTS = 44100 * 20;   // 30 seconds of storage
#define MAX_BUFFERS 5			 // for stWHDR

// standard variables for sound input
HWAVEIN      hWaveIn;
WAVEFORMATEX stWFEX;
WAVEHDR stWHDR[MAX_BUFFERS];
HMMIO hOPFile;
MMIOINFO stmmIF;
MMCKINFO stckOut, stckOutRIFF;

LPWSTR recordname;		// name of wav file. setrecordname changes this and startRecording uses this

void CALLBACK waveInProc(HWAVEIN hwi, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2)
{
	// used in 'createDevice'. waveInOpen will call waveInProc whenever the sound buffer is filled with data.
	WAVEHDR *pHdr = (WAVEHDR *)dwParam1;
	MMRESULT result;
	switch (uMsg)
	{
	case WIM_CLOSE:
		break;

	case WIM_DATA:
	{
		mmioWrite(hOPFile, pHdr->lpData, pHdr->dwBytesRecorded);			// writes sound data to file from sound buffer
		result = waveInAddBuffer(hWaveIn, pHdr, sizeof(WAVEHDR));
	}
	break;

	case WIM_OPEN:
		break;

	default:
		break;
	}
}

void createDevice(const LPWSTR name)
	{
		MMRESULT result;

		// stWFEX, input to sound buffer preparation
		ZeroMemory(&stWFEX, sizeof(WAVEFORMATEX));
		ZeroMemory(&stWHDR, sizeof(WAVEHDR));

		int sampleRate = 44100;

		stWFEX.wFormatTag = WAVE_FORMAT_PCM;
		stWFEX.nChannels = 1;
		stWFEX.wBitsPerSample = 16;
		stWFEX.nSamplesPerSec = 16000;
		stWFEX.nBlockAlign = stWFEX.nChannels*stWFEX.wBitsPerSample / 8;
		stWFEX.nAvgBytesPerSec = stWFEX.nSamplesPerSec*stWFEX.nBlockAlign;
		stWFEX.cbSize = 0;

		result = waveInOpen(&hWaveIn, WAVE_MAPPER, &stWFEX, (DWORD_PTR)waveInProc, 0L, CALLBACK_FUNCTION);

		// stmmIF, input to file preparation, contain creation of wave file structure
		ZeroMemory(&stmmIF, sizeof(MMIOINFO));
		hOPFile = mmioOpen(name, &stmmIF, MMIO_WRITE | MMIO_CREATE);

		if (hOPFile == NULL)
			MessageBoxA(NULL, "Error creating wav file.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);

		ZeroMemory(&stckOutRIFF, sizeof(MMCKINFO));

		stckOutRIFF.fccType = mmioFOURCC('W', 'A', 'V', 'E');
		result = mmioCreateChunk(hOPFile, &stckOutRIFF, MMIO_CREATERIFF);

		ZeroMemory(&stckOut, sizeof(MMCKINFO));

		stckOut.ckid = mmioFOURCC('f', 'm', 't', ' ');
		stckOut.cksize = sizeof(stWFEX);
		result = mmioCreateChunk(hOPFile, &stckOut, 0);
		mmioWrite(hOPFile, (HPSTR)&stWFEX, sizeof(stWFEX));

		result = mmioAscend(hOPFile, &stckOut, 0);

		stckOut.ckid = mmioFOURCC('d', 'a', 't', 'a');
		result = mmioCreateChunk(hOPFile, &stckOut, 0);
	}

void preparebuffer()
	{
		MMRESULT result;

		// stWHDR, create multiple buffers for sound data. max_buffers = 5
		for (int count(0); count < MAX_BUFFERS; ++count)
		{
			stWHDR[count].lpData = (LPSTR)waveIn;
			stWHDR[count].dwBufferLength = NUMPTS * 2;
			stWHDR[count].dwUser = 0L;
			stWHDR[count].dwBytesRecorded = 0;
			stWHDR[count].dwFlags = 0L;
			stWHDR[count].dwLoops = 0L;

			result = waveInPrepareHeader(hWaveIn, &stWHDR[count], sizeof(WAVEHDR));
			result = waveInAddBuffer(hWaveIn, &stWHDR[count], sizeof(WAVEHDR));
		}

	}

void destroyDevice()
	{
	// cleanup of things used to accept and store sound buffer
		MMRESULT result;

		result = waveInStop(hWaveIn);

		for (int count(0); count < MAX_BUFFERS; ++count)
		{
			result = waveInUnprepareHeader(hWaveIn, &stWHDR[count], sizeof(WAVEHDR));
			ZeroMemory(&stWHDR[count], sizeof(WAVEHDR));
		}
		
		result = waveInClose(hWaveIn);

		if (hOPFile)
		{
			result = mmioAscend(hOPFile, &stckOut, 0);
			result = mmioAscend(hOPFile, &stckOutRIFF, 0);
			mmioClose(hOPFile, 0);
			hOPFile = NULL;
		}

		hWaveIn = NULL;
	}

void startRecording()
	{
		MMRESULT result;

		createDevice(recordname);					// create input and wavein
		preparebuffer();							// create buffers
		result = waveInStart(hWaveIn);				// start
		int tinyseconds(0);							// very rough time estimate through incrementations

		while (1)
		{
			Sleep(1);
			++tinyseconds;
			if ((GetKeyState(0x53) & 0x80) != 0)	// 's' key
			{
				break;
			}
			if (tinyseconds == 20000)				// check if x seconds have passed. if so, break to avoid running out of memory. though technically buffers can store up to 2 mins 30 secs
			{
				break;
			}
		}

		// close
		destroyDevice();							// delete pointers etc, cleanup, close devices
	}

void setrecordname(const LPWSTR name)
{
	recordname = name;			// startRecording() is called through a thread so cannot accept input for wav filename. this function sets the wav filename before startRecording is called
}
