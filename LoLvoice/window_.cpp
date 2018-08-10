#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <ShObjIdl.h>
#include <string>
#include <thread>
#include <Winuser.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "resource.h"
#include <ShlObj.h>
#include <CommCtrl.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc_set(HWND settings, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc_ibm(HWND settings_ibm, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc_overdrive(HWND settings_overdrive, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc_path(HWND hwnd_path, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc_speech(HWND hwnd_speech, UINT uMsg, WPARAM wParam, LPARAM lParam);

std::string configfinalpath;
std::string configtempfinalpath;
std::string configinifinalpath;
char* folderPath = nullptr;
int len(0);
std::string folderPathstr;
char* gearbmp = nullptr;
char* lmagebmp = nullptr;
char* lmage_stopbmp = nullptr;
char* imagebmp = nullptr;
char* ground_lightbmp = nullptr;
char* groundbmp = nullptr;
char* sphinxbmp = nullptr;
char* ibmsttbmp = nullptr;
char* overdrivebmp = nullptr;
HBITMAP hBitmap01 = NULL;
HBITMAP hBitmap02 = NULL;
HBITMAP hBitmap03 = NULL;
HBITMAP hBitmap04 = NULL;
HBITMAP hBitmap05 = NULL;
HBITMAP hBitmap06 = NULL;
HBITMAP hBitmap07 = NULL;
HBITMAP hBitmap08 = NULL;

void startRecord();
void openMic();
void closeMic();
void miclose();
void inputFile();
void defineconfig();
bool psChecker();
bool checkforhandlenull();
bool checkifsphinxfilesnotloaded();

bool settingsFocus = true;
bool settingsFocus_ibm = true;
bool settingsFocus_overdrive = true;
int record(0);     // keep check of times a button is pressed
void startRecording();
void setrecordname(const LPWSTR name);
void recordsoundfiles(const LPWSTR filename, const LPWSTR nextline);
void recordlastsoundfiles(const LPWSTR filename);
char* returnPath();
int returnSizee();
std::string sconvert(const char *pCh, int arraySize);
void initializePaths();
void renamefolder(const char* oldname, const int sizeofoldname, const char* newname, const int sizeofnewname);
std::string loadconfigfile();
std::string loadconfiginifile();
std::string loadconfigtempfile();
std::string loadpathfile();
std::string loadpathinifile();
std::string loadpathtempfile();
std::string loaduserpassfile();
std::string loaduserpasstempfile();
void loadbitmaps(char* bitnameptr, const char* bitname, const int sizeofbitname);
void loadbitmaps_default(char* bitnameptr, const char* bitname, const int sizeofbitname);
bool checkiffoldersexist(std::string folder);

void detectKeyPress();
void detectOverdriveKeyPress();
int viewKey();
int viewOverdriveKey();
LPCTSTR intToKey(int hex);
void loadVariablesWindow();
void createPathtoExeDirectory(char* &defaultpath, int &length);

bool isSphinx = false;
bool isIbm = false;
bool isOverdrive = false;
void startIbmTts();
void openIbmTts();
void closeIbmtts();
void endIbmstt();
void overdriveKeybind();
void changeKeybind();

std::string loadibmoutputfile();
std::string loadibmoutputtempfile();
std::string loadsphinxoutputfile();
std::string loadsphinxoutputtempfile();

struct StateInfo {

	int state;
};

HINSTANCE hInst;
WNDCLASS wc_set = {}, wc_ibm = {}, wc_overdrive = {};
HINSTANCE hinst_set, hinst_path, hinst_speech, hinst_ibm, hinst_overdrive;
HWND setwindow, setkeybind, adaptbutton, adaptchange, adaptbuttoncont, adaptbuttoncont2, path_input, parentwindow, pathactwindow, pathButton, speechwindow, username, password, setuserpassButton, setoverdrivebind, windowforsettings;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	// initialize variables
	std::thread recording(startRecord);
	std::thread ibmstting(startIbmTts);
	int checkIfnegative = returnSizee();
	while (checkIfnegative <= 0)
	{
		checkIfnegative = returnSizee();
	}
	loadVariablesWindow();

	// create window for choosing between sphinx or IBMSTT
	WNDCLASS wc_speech = {};
	wc_speech.lpfnWndProc = WindowProc_speech;
	wc_speech.hInstance = hinst_speech;
	wc_speech.lpszClassName = L"Speech Library";

	RegisterClass(&wc_speech);

	HWND hwnd_speech = CreateWindowEx(
		0,                              // Optional window styles.
		L"Speech Library",                     // Window class
		L"LoLvoice",				    // Window text
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,            // Window style
												// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 500,

		NULL,       // Parent window    
		NULL,       // Menu
		hinst_speech,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd_speech == NULL)
	{
		return 0;
	}

	speechwindow = hwnd_speech;

	// Register the window class.
	const wchar_t CLASS_NAME[] = L"LoLvoice Window Class";

	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.hCursor = LoadCursor(0, IDC_ARROW);

	wc_set.lpfnWndProc = WindowProc_set;
	wc_set.hInstance = hinst_set;
	wc_set.lpszClassName = L"LoLvoice settings";

	wc_ibm.lpfnWndProc = WindowProc_ibm;
	wc_ibm.hInstance = hinst_ibm;
	wc_ibm.lpszClassName = L"LoLvoice settings ibm";

	wc_overdrive.lpfnWndProc = WindowProc_overdrive;
	wc_overdrive.hInstance = hinst_overdrive;
	wc_overdrive.lpszClassName = L"LoLvoice settings overdrive";

	hInst = hInstance;

	RegisterClass(&wc);
	RegisterClass(&wc_set);
	RegisterClass(&wc_ibm);
	RegisterClass(&wc_overdrive);

	// Create the window.

	StateInfo *pState = new StateInfo;

	if (pState == NULL)
	{
		return 0;
	}

	// Initialize the structure members (not shown).

	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		L"LoLvoice",				    // Window text
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,            // Window style

																			 // Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 500,

		NULL,       // Parent window    
		NULL,       // Menu
		hInstance,  // Instance handle
		pState        // Additional application data
	);

	if (hwnd == NULL)
	{
		return 0;
	}

	parentwindow = hwnd;

	RECT rc;
	GetWindowRect(hwnd, &rc);
	int xPos = (GetSystemMetrics(SM_CXSCREEN) - rc.right) / 2;
	int yPos = (GetSystemMetrics(SM_CYSCREEN) - rc.bottom) / 2;
	SetWindowPos(hwnd, 0, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	WNDCLASS wc_path = {};
	wc_path.lpfnWndProc = WindowProc_path;
	wc_path.hInstance = hinst_path;
	wc_path.lpszClassName = L"Path setting";

	RegisterClass(&wc_path);

	HWND hwnd_path = CreateWindowEx(
		0,                              // Optional window styles.
		L"Path setting",                     // Window class
		L"LoLvoice",				    // Window text
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX,            // Window style

																			 // Size and position
		xPos, yPos, 600, 200,

		NULL,       // Parent window    
		NULL,       // Menu
		hinst_path,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd == NULL)
	{
		return 0;
	}

	pathactwindow = hwnd_path;

	int firstornot(0);
	std::string pathfinalpath = loadpathfile();
	std::string pathline;
	std::ifstream pathfile(pathfinalpath);
	pathfile >> firstornot;
	pathfile.close();
	if (firstornot == 0)
	{
		ShowWindow(pathactwindow, SW_SHOW);
	}
	if (firstornot == 1)
	{
		ShowWindow(hwnd_speech, SW_SHOW);
	}

	// Run the message loop.
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	recording.join();
	ibmstting.join();

	return 0;
}

inline StateInfo* GetAppState(HWND hwnd)
{
	LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
	StateInfo *pState = reinterpret_cast<StateInfo*>(ptr);
	return pState;
}

// Functions regarding buttons

WNDPROC OldButtonProc;
WNDPROC OldButtonProc2;
WNDPROC OldButtonProc3;
WNDPROC OldButtonProc4;
WNDPROC OldButtonProc5;
WNDPROC OldButtonProc6;
WNDPROC OldButtonProc7;
WNDPROC OldButtonProc8;
WNDPROC OldButtonProc9;
WNDPROC OldButtonProc10;
WNDPROC OldButtonProc11;
WNDPROC OldButtonProc12;
WNDPROC OldButtonProc13;
WNDPROC OldButtonProc14;
WNDPROC OldButtonProc15;
WNDPROC OldButtonProc16;
WNDPROC OldButtonProc17;

LRESULT CALLBACK ButtonProc(HWND hwnd, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		if (isSphinx == true)
		{
			openMic();
			if (psChecker())
			{
				Sleep(3000);
				if (psChecker())
				{
					Sleep(7 * 1000);
					if (psChecker())
					{
						MessageBoxA(NULL, "Error locating 'en-us' folder. The program will now exit.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
						exit(-1);
					}
				}
			}
		}

		if (isIbm == true)
		{
			openIbmTts();
			if (checkforhandlenull())
			{
				Sleep(3000);
				if (checkforhandlenull())
				{
					Sleep(7 * 1000);
					if (checkforhandlenull())
					{
						Sleep(3 * 1000);
						if (checkforhandlenull())
						{
							Sleep(7 * 1000);
							if (checkforhandlenull())
							{
								MessageBoxA(NULL, "Error initiating connection to ibm. The username/password you provided might be incorrect. The program will now exit.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
								exit(-1);
							}
						}
					}
				}
			}
		}

		if (isOverdrive == true)
		{
			openIbmTts();
			openMic();
			if (psChecker())
			{
				Sleep(3000);
				if (psChecker())
				{
					Sleep(7 * 1000);
					if (psChecker())
					{
						MessageBoxA(NULL, "Error locating 'en-us' folder. The program will now exit.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
						exit(-1);
					}
				}
			}
			if (checkforhandlenull())
			{
				Sleep(3000);
				if (checkforhandlenull())
				{
					Sleep(7 * 1000);
					if (checkforhandlenull())
					{
						MessageBoxA(NULL, "Error initiating connection to ibm. The username/password you provided might be incorrect. The program will now exit.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
						exit(-1);
					}
				}
			}
		}
	}
		break;
	}
	return CallWindowProc(OldButtonProc, hwnd, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc2(HWND hwnd, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		if (isSphinx == true)
		{
			closeMic();
		}

		if (isIbm == true)
		{
			closeIbmtts();
		}

		if (isOverdrive == true)
		{
			closeIbmtts();
			closeMic();
		}
	}
		break;
	}
	return CallWindowProc(OldButtonProc2, hwnd, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc3(HWND hwnd, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:

		
	//	HMENU hmenu;

	// hmenu = LoadMenu(hinst_set, MAKEINTRESOURCE(ID_MENU));
	
		RECT rc;
		GetWindowRect(hwnd, &rc);
		int xPos = (GetSystemMetrics(SM_CXSCREEN) - rc.right) / 2;
		int yPos = (GetSystemMetrics(SM_CYSCREEN) - rc.bottom) / 2;

		if (isSphinx == true)
		{
			HWND settings = CreateWindowEx(
				0,                              // Optional window styles.
				L"LoLvoice settings",                     // Window class
				L"Settings",				    // Window text
				WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX | WS_POPUPWINDOW,            // Window style

																							  // Size and position
				xPos, yPos, 400, 300,

				NULL,       // Parent window    
				NULL,       // Menu
				hinst_set,  // Instance handle
				NULL        // Additional application data
			);

			if (settings == NULL)
			{
				return 0;
			}

			windowforsettings = settings;

			if (settingsFocus == true)
			{
				SetWindowPos(settings, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				ShowWindow(settings, SW_NORMAL);
				settingsFocus = false;
			}
			else
			{
				// nothing here
			}
		}

		if (isIbm == true)
		{
			HWND settings_ibm = CreateWindowEx(
				0,                              // Optional window styles.
				L"LoLvoice settings ibm",                     // Window class
				L"Settings",				    // Window text
				WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX | WS_POPUPWINDOW,            // Window style

																							  // Size and position
				xPos, yPos, 400, 300,

				NULL,       // Parent window    
				NULL,       // Menu
				hinst_ibm,  // Instance handle
				NULL        // Additional application data
			);

			if (settings_ibm == NULL)
			{
				return 0;
			}

			windowforsettings = settings_ibm;

			if (settingsFocus_ibm == true)
			{
				SetWindowPos(settings_ibm, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				ShowWindow(settings_ibm, SW_NORMAL);
				settingsFocus_ibm = false;
			}
			else
			{
				// nothing here
			}
		}

		if (isOverdrive == true)
		{
			HWND settings_overdrive = CreateWindowEx(
				0,                              // Optional window styles.
				L"LoLvoice settings overdrive",                     // Window class
				L"Settings",				    // Window text
				WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX | WS_POPUPWINDOW,            // Window style

																							  // Size and position
				xPos, yPos, 400, 300,

				NULL,       // Parent window    
				NULL,       // Menu
				hinst_overdrive,  // Instance handle
				NULL        // Additional application data
			);

			if (settings_overdrive == NULL)
			{
				return 0;
			}

			windowforsettings = settings_overdrive;

			if (settingsFocus_overdrive == true)
			{
				SetWindowPos(settings_overdrive, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				ShowWindow(settings_overdrive, SW_NORMAL);
				settingsFocus_overdrive = false;
			}
			else
			{
				// nothing here
			}
		}

		break;
	}
	return CallWindowProc(OldButtonProc3, hwnd, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc4(HWND settings, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		int bufferLen = GetWindowTextLength(setwindow) + 1; // why send the message twice?
		std::string data(bufferLen, '\0');
		GetWindowTextA(setwindow, &data[0], bufferLen);

		std::string templine;
		std::ofstream mytempfile;
		mytempfile.open(configtempfinalpath, std::ios::app | std::ios::in);
		std::ifstream myfile(configinifinalpath);

		if (myfile.is_open())
		{
			while (getline(myfile, templine))
			{
				mytempfile << templine << data;
			}
		}
		myfile.close();
		mytempfile.close();

		char* finalconfigpatharray = new char[configfinalpath.length()/sizeof(configfinalpath[0]) + 1];
		char* finalconfigtemppatharray = new char[configtempfinalpath.length() / sizeof(configtempfinalpath[0]) + 1];

		for (int count(0); count<configfinalpath.length() / sizeof(configfinalpath[0]); ++count)
		{
			finalconfigpatharray[count] = configfinalpath[count];
		}
		finalconfigpatharray[configfinalpath.length() / sizeof(configfinalpath[0])] = '\0';
		for (int count(0); count < configtempfinalpath.length() / sizeof(configtempfinalpath[0]); ++count)
		{
			finalconfigtemppatharray[count] = configtempfinalpath[count];
		}
		finalconfigtemppatharray[configtempfinalpath.length() / sizeof(configtempfinalpath[0])] = '\0';

		remove(finalconfigpatharray);
		rename(finalconfigtemppatharray, finalconfigpatharray);
		inputFile();
		defineconfig();

		delete[] finalconfigpatharray;
		finalconfigpatharray = nullptr;
		delete[] finalconfigtemppatharray;
		finalconfigtemppatharray = nullptr;
	}
		break;
	}
	return CallWindowProc(OldButtonProc4, settings, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc5(HWND settings, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		LPCTSTR setting = L"Enter new key: ";

		SetWindowText(
			setkeybind,
			setting
		);

		std::thread keying(detectKeyPress);
		keying.join();

		LPCTSTR keybind = intToKey(viewKey());

		SetWindowText(
			setkeybind,
			keybind
		);
		changeKeybind();
	}
		break;
	}

	return CallWindowProc(OldButtonProc5, settings, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc6(HWND settings, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		// introduction
		LPCTSTR change1 = L"Please speak the following sentences into your\
 microphone";

		SetWindowText(
			adaptchange,
			change1
		);

		ShowWindow(adaptbutton, SW_HIDE);
		ShowWindow(adaptbuttoncont, SW_SHOW);
	}
		break;
	}
	return CallWindowProc(OldButtonProc6, settings, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc7(HWND settings, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		LPCTSTR change2 = L"Press 'Record' on the screen when you begin and press 'S' on the keyboard when done";

		SetWindowText(
			adaptchange,
			change2
		);

		ShowWindow(adaptbuttoncont, SW_HIDE);
		ShowWindow(adaptbuttoncont2, SW_SHOW);
	}
	break;
	}
	return CallWindowProc(OldButtonProc7, settings, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc8(HWND settings, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		if (record == 20)
		{
			recordlastsoundfiles(L"arctic_0020.wav");
			record = 0;
		}
		if (record == 19)
		{
			recordsoundfiles(L"arctic_0019.wav", L"Say: the inhibitor and the nexus must be destroyed to win the game");
			++record;
		}
		if (record == 18)
		{
			recordsoundfiles(L"arctic_0018.wav", L"Say: bot laners and top laner switched position to exert map pressure");
			++record;
		}
		if (record == 17)
		{
			recordsoundfiles(L"arctic_0017.wav", L"Say: go flank their back line while we tank and peel for our carries in the front line");
			++record;
		}
		if (record == 16)
		{
			recordsoundfiles(L"arctic_0016.wav", L"Say: be passive and play passively we can't afford to play aggressively");
			++record;
		}
		if (record == 15)
		{
			recordsoundfiles(L"arctic_0015.wav", L"Say: look for engages when you can and be more aggressive");
			++record;
		}
		if (record == 14)
		{
			recordsoundfiles(L"arctic_0014.wav", L"Say: let's group up to get objectives while we have the elder drake");
			++record;
		}
		if (record == 13)
		{
			recordsoundfiles(L"arctic_0013.wav", L"Say: ultimates that channel can be interrupted");
			++record;
		}
		if (record == 12)
		{
			recordsoundfiles(L"arctic_0012.wav", L"Say: life steal and spell vamp are good stats to trade with");
			++record;
		}
		if (record == 11)
		{
			recordsoundfiles(L"arctic_0011.wav", L"Say: the red buff and blue buffs regenerates health and mana");
			++record;
		}
		if (record == 10)
		{
			recordsoundfiles(L"arctic_0010.wav", L"Say: use your trinket and get a sweeper to sweep the river");
			++record;
		}
		if (record == 9)
		{
			recordsoundfiles(L"arctic_0009.wav", L"Say: champions like evelynn can stealth while in the fog of war");
			++record;
		}
		if (record == 8)
		{
			recordsoundfiles(L"arctic_0008.wav", L"Say: heimerdinger has stopwatch so watch out while we dive");
			++record;
		}
		if (record == 7)
		{
			recordsoundfiles(L"arctic_0007.wav", L"Say: we need to play around baron unlike our opponent who is playing around dragon");
			++record;
		}
		if (record == 6)
		{
			recordsoundfiles(L"arctic_0006.wav", L"Say: i will be right back currently going back to shop for items so play safe");
			++record;
		}
		if (record == 5)
		{
			recordsoundfiles(L"arctic_0005.wav", L"Say: bot lane is easy to gank we have cleared visions with control wards");
			++record;
		}
		if (record == 4)
		{
			recordsoundfiles(L"arctic_0004.wav", L"Say: focus aatrox in team fights and place all your c_c on him");
			++record;
		}
		if (record == 3)
		{
			recordsoundfiles(L"arctic_0003.wav", L"Say: go ward around while I push in the wave into the enemy turret");
			++record;
		}
		if (record == 2)
		{
			recordsoundfiles(L"arctic_0002.wav", L"Say: bottom lane's a_d_c has her ultimate and flash on cooldown");
			++record;
		}
		if (record == 1)
		{
			recordsoundfiles(L"arctic_0001.wav", L"Say: the enemy jungler is camping the mid lane");
			++record;
		}
		if (record == 0)
		{
			// output
			SetWindowText(
				adaptchange,
				L"Say: the bush near top and where I pinged has been warded"
			);
			// button
			SetWindowText(
				adaptbuttoncont2,
				L"Record"
			);
			++record;
		}
	}
	break;
	}
	return CallWindowProc(OldButtonProc8, settings, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc9(HWND hwnd_path, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		// get input
		int bufferLen = GetWindowTextLength(path_input) + 1; // why send the message twice?
		std::string data(bufferLen, '\0');
		GetWindowTextA(path_input, &data[0], bufferLen);

		std::string templine;
		std::ofstream mytempfile;
		mytempfile.open(configtempfinalpath, std::ios::app | std::ios::in);
		std::ifstream myfile(configinifinalpath);

		if (myfile.is_open())
		{
			while (getline(myfile, templine))
			{
				mytempfile << templine << data;
			}
		}
		myfile.close();
		mytempfile.close();

		char* finalconfigpatharray = new char[configfinalpath.length() / sizeof(configfinalpath[0]) + 1];
		char* finalconfigtemppatharray = new char[configtempfinalpath.length() / sizeof(configtempfinalpath[0]) + 1];

		for (int count(0); count<configfinalpath.length() / sizeof(configfinalpath[0]); ++count)
		{
			finalconfigpatharray[count] = configfinalpath[count];
		}
		finalconfigpatharray[configfinalpath.length() / sizeof(configfinalpath[0])] = '\0';
		for (int count(0); count < configtempfinalpath.length() / sizeof(configtempfinalpath[0]); ++count)
		{
			finalconfigtemppatharray[count] = configtempfinalpath[count];
		}
		finalconfigtemppatharray[configtempfinalpath.length() / sizeof(configtempfinalpath[0])] = '\0';

		remove(finalconfigpatharray);
		rename(finalconfigtemppatharray, finalconfigpatharray);
		inputFile();
		defineconfig();

		delete[] finalconfigpatharray;
		finalconfigpatharray = nullptr;
		delete[] finalconfigtemppatharray;
		finalconfigtemppatharray = nullptr;

		// check if path is correctly defined
		if (psChecker() == false)
		{
			loadVariablesWindow();
			ShowWindow(speechwindow, SW_SHOW);
			ShowWindow(pathactwindow, SW_HIDE);

			std::string finalpath = loadpathfile();
			std::string pathtemp = loadpathtempfile();

			std::string templine;
			std::ofstream mytempfile;
			mytempfile.open(pathtemp, std::ios::app | std::ios::in);
			mytempfile << 1;
			mytempfile.close();

			char* finalpatharray = new char[finalpath.length() / sizeof(finalpath[0]) + 1];
			char* finaltemppatharray = new char[pathtemp.length() / sizeof(pathtemp[0]) + 1];

			for (int count(0); count<finalpath.length() / sizeof(finalpath[0]); ++count)
			{
				finalpatharray[count] = finalpath[count];
			}
			finalpatharray[finalpath.length() / sizeof(finalpath[0])] = '\0';
			for (int count(0); count < pathtemp.length() / sizeof(pathtemp[0]); ++count)
			{
				finaltemppatharray[count] = pathtemp[count];
			}
			finaltemppatharray[pathtemp.length() / sizeof(pathtemp[0])] = '\0';

			remove(finalpatharray);
			rename(finaltemppatharray, finalpatharray);

			delete[] finalpatharray;
			finalpatharray = nullptr;
			delete[] finaltemppatharray;
			finaltemppatharray = nullptr;
		}
		else
		{
			SetWindowText(
				pathButton,
				L"Error loading path. Please try again."
			);
			std::string finalpath = loadpathfile();
			std::string pathtemp = loadpathtempfile();

			std::string templine;
			std::ofstream mytempfile;
			mytempfile.open(pathtemp, std::ios::app | std::ios::in);
			mytempfile << 0;
			mytempfile.close();

			char* finalpatharray = new char[finalpath.length() / sizeof(finalpath[0]) + 1];
			char* finaltemppatharray = new char[pathtemp.length() / sizeof(pathtemp[0]) + 1];

			for (int count(0); count<finalpath.length() / sizeof(finalpath[0]); ++count)
			{
				finalpatharray[count] = finalpath[count];
			}
			finalpatharray[finalpath.length() / sizeof(finalpath[0])] = '\0';
			for (int count(0); count < pathtemp.length() / sizeof(pathtemp[0]); ++count)
			{
				finaltemppatharray[count] = pathtemp[count];
			}
			finaltemppatharray[pathtemp.length() / sizeof(pathtemp[0])] = '\0';

			remove(finalpatharray);
			rename(finaltemppatharray, finalpatharray);

			delete[] finalpatharray;
			finalpatharray = nullptr;
			delete[] finaltemppatharray;
			finaltemppatharray = nullptr;

			Sleep(2 * 1000);
			SetWindowText(
				pathButton,
				L"Set Path"
			);
		}
	}
	break;
	}

	return CallWindowProc(OldButtonProc9, hwnd_path, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc10(HWND hwnd_speech, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		void endIbmstt();
		isSphinx = true;
		int firstornot(0);
		std::string pathfinalpath = loadpathfile();
		std::string pathline;
		std::ifstream pathfile(pathfinalpath);
		pathfile >> firstornot;
		pathfile.close();

		if (firstornot == 0)
		{
			ShowWindow(pathactwindow, SW_SHOW);
		}
		if (firstornot == 1)
		{
			if (psChecker())
			{
				Sleep(3 * 1000);
				if (psChecker())
				{
					Sleep(7 * 1000);
					ShowWindow(parentwindow, SW_SHOW);
				}
				else
				{
					ShowWindow(parentwindow, SW_SHOW);
				}
			}
			else
			{
				ShowWindow(parentwindow, SW_SHOW);
			}
		}
		ShowWindow(speechwindow, SW_HIDE);
		DeleteObject(hBitmap06);
		DeleteObject(hBitmap07);
		DeleteObject(hBitmap08);
	}
		break;
	}
	return CallWindowProc(OldButtonProc10, hwnd_speech, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc11(HWND hwnd_speech, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		miclose();
		isIbm = true;
		int firstornot(0);
		std::string pathfinalpath = loadpathfile();
		std::string pathline;
		std::ifstream pathfile(pathfinalpath);
		pathfile >> firstornot;
		pathfile.close();

		if (firstornot == 0)
		{
			ShowWindow(pathactwindow, SW_SHOW);
		}
		if (firstornot == 1)
		{
			if (checkforhandlenull())
			{
				Sleep(3 * 1000);
				if (checkforhandlenull())
				{
					Sleep(7 * 1000);
					ShowWindow(parentwindow, SW_SHOW);
				}
				else
				{
					ShowWindow(parentwindow, SW_SHOW);
				}
			}
			else
			{
				ShowWindow(parentwindow, SW_SHOW);
			}
		}
		ShowWindow(speechwindow, SW_HIDE);
		DeleteObject(hBitmap06);
		DeleteObject(hBitmap07);
		DeleteObject(hBitmap08);
	}
		break;
	}
	return CallWindowProc(OldButtonProc11, hwnd_speech, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc12(HWND hwnd_speech, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		isOverdrive = true;
		int firstornot(0);
		std::string pathfinalpath = loadpathfile();
		std::string pathline;
		std::ifstream pathfile(pathfinalpath);
		pathfile >> firstornot;
		pathfile.close();

		if (firstornot == 0)
		{
			ShowWindow(pathactwindow, SW_SHOW);
		}
		if (firstornot == 1)
		{
			if (psChecker())
			{
				Sleep(5 * 1000);
				if (checkforhandlenull())
				{
					Sleep(5 * 1000);
					ShowWindow(parentwindow, SW_SHOW);
				}
				else
				{
					ShowWindow(parentwindow, SW_SHOW);
				}
			}
			else
			{
				if (checkforhandlenull())
				{
					Sleep(5 * 1000);
					ShowWindow(parentwindow, SW_SHOW);
				}
				else
				{
					ShowWindow(parentwindow, SW_SHOW);
				}
			}
		}
		ShowWindow(speechwindow, SW_HIDE);
		DeleteObject(hBitmap06);
		DeleteObject(hBitmap07);
		DeleteObject(hBitmap08);
		overdriveKeybind();
	}
		break;
	}
	return CallWindowProc(OldButtonProc12, hwnd_speech, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc13(HWND settings_ibm, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		int bufferLen = GetWindowTextLength(username) + 1; // why send the message twice?
		std::string user(bufferLen, '\0');
		GetWindowTextA(username, &user[0], bufferLen);
		int bufferLen2 = GetWindowTextLength(password) + 1; // why send the message twice?
		std::string pass(bufferLen2, '\0');
		GetWindowTextA(password, &pass[0], bufferLen2);

		std::string userpasspath = loaduserpassfile();
		std::string userpasstemppath = loaduserpasstempfile();

		std::string usernamepassword((bufferLen + bufferLen2 - 1), '\0');
		for (int count(0); count < bufferLen - 1; ++count)
		{
			usernamepassword[count] = user[count];
		}
		usernamepassword[bufferLen - 1] = ':';
		for (int count(0); count < bufferLen2; ++count)
		{
			usernamepassword[bufferLen + count] = pass[count];
		}

		std::ofstream mytempfile;
		mytempfile.open(userpasstemppath, std::ios::app | std::ios::in);
		mytempfile << usernamepassword;
		mytempfile.close();

		char* finaluserpasspatharray = new char[userpasspath.length() / sizeof(userpasspath[0]) + 1];
		char* userpasstemppatharray = new char[userpasstemppath.length() / sizeof(userpasstemppath[0]) + 1];

		for (int count(0); count<userpasspath.length() / sizeof(userpasspath[0]); ++count)
		{
			finaluserpasspatharray[count] = userpasspath[count];
		}
		finaluserpasspatharray[userpasspath.length() / sizeof(userpasspath[0])] = '\0';
		for (int count(0); count < userpasstemppath.length() / sizeof(userpasstemppath[0]); ++count)
		{
			userpasstemppatharray[count] = userpasstemppath[count];
		}
		userpasstemppatharray[userpasstemppath.length() / sizeof(userpasstemppath[0])] = '\0';

		remove(finaluserpasspatharray);
		rename(userpasstemppatharray, finaluserpasspatharray);

		delete[] finaluserpasspatharray;
		finaluserpasspatharray = nullptr;
		delete[] userpasstemppatharray;
		userpasstemppatharray = nullptr;

		MessageBoxA(NULL, "Username and password saved. A restart of the program is needed. The program will now exit.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
		exit(-1);
	}
		break;
	}
	return CallWindowProc(OldButtonProc13, settings_ibm, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc14(HWND settings_ibm, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		ShellExecute(0, 0, L"https://idaas.iam.ibm.com/idaas/mtfim/sps/authsvc?PolicyId=urn:ibm:security:authentication:asf:basicldapuser", 0, 0, SW_SHOW);
	}
	break;
	}
	return CallWindowProc(OldButtonProc14, settings_ibm, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc15(HWND settings_overdrive, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		LPCTSTR setting = L"Enter new key: ";

		SetWindowText(
			setoverdrivebind,
			setting
		);

		std::thread keying(detectOverdriveKeyPress);
		keying.join();

		LPCTSTR keybind = intToKey(viewOverdriveKey());

		SetWindowText(
			setoverdrivebind,
			keybind
		);
		overdriveKeybind();
	}
	break;
	}

	return CallWindowProc(OldButtonProc15, settings_overdrive, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc16(HWND settings_ibm, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		int ibmoutputmode_int(0);
		std::string ibmoutputmode = loadibmoutputfile();
		std::string ibmoutputmode_temp = loadibmoutputtempfile();
		std::ifstream pathfile(ibmoutputmode);
		pathfile >> ibmoutputmode_int;
		pathfile.close();

		if (ibmoutputmode_int == 0)
		{
			std::ofstream mytempfile;
			mytempfile.open(ibmoutputmode_temp, std::ios::app | std::ios::in);
			mytempfile << 1;
			mytempfile.close();

			char* finalibmoutputarray = new char[ibmoutputmode.length() / sizeof(ibmoutputmode[0]) + 1];
			char* ibmoutputtemparray = new char[ibmoutputmode_temp.length() / sizeof(ibmoutputmode_temp[0]) + 1];

			for (int count(0); count<ibmoutputmode.length() / sizeof(ibmoutputmode[0]); ++count)
			{
				finalibmoutputarray[count] = ibmoutputmode[count];
			}
			finalibmoutputarray[ibmoutputmode.length() / sizeof(ibmoutputmode[0])] = '\0';
			for (int count(0); count < ibmoutputmode_temp.length() / sizeof(ibmoutputmode_temp[0]); ++count)
			{
				ibmoutputtemparray[count] = ibmoutputmode_temp[count];
			}
			ibmoutputtemparray[ibmoutputmode_temp.length() / sizeof(ibmoutputmode_temp[0])] = '\0';

			remove(finalibmoutputarray);
			rename(ibmoutputtemparray, finalibmoutputarray);

			delete[] finalibmoutputarray;
			finalibmoutputarray = nullptr;
			delete[] ibmoutputtemparray;
			ibmoutputtemparray = nullptr;
		}
		if (ibmoutputmode_int == 1)
		{
			std::ofstream mytempfile;
			mytempfile.open(ibmoutputmode_temp, std::ios::app | std::ios::in);
			mytempfile << 0;
			mytempfile.close();

			char* finalibmoutputarray = new char[ibmoutputmode.length() / sizeof(ibmoutputmode[0]) + 1];
			char* ibmoutputtemparray = new char[ibmoutputmode_temp.length() / sizeof(ibmoutputmode_temp[0]) + 1];

			for (int count(0); count<ibmoutputmode.length() / sizeof(ibmoutputmode[0]); ++count)
			{
				finalibmoutputarray[count] = ibmoutputmode[count];
			}
			finalibmoutputarray[ibmoutputmode.length() / sizeof(ibmoutputmode[0])] = '\0';
			for (int count(0); count < ibmoutputmode_temp.length() / sizeof(ibmoutputmode_temp[0]); ++count)
			{
				ibmoutputtemparray[count] = ibmoutputmode_temp[count];
			}
			ibmoutputtemparray[ibmoutputmode_temp.length() / sizeof(ibmoutputmode_temp[0])] = '\0';

			remove(finalibmoutputarray);
			rename(ibmoutputtemparray, finalibmoutputarray);

			delete[] finalibmoutputarray;
			finalibmoutputarray = nullptr;
			delete[] ibmoutputtemparray;
			ibmoutputtemparray = nullptr;
		}

		MessageBoxA(NULL, "Switching output mode requires restarting LoLvoice. The program will now exit.", "Restart", MB_ICONWARNING | MB_DEFBUTTON2);
		exit(-1);
	}
	break;
	}

	return CallWindowProc(OldButtonProc16, settings_ibm, uMsg, wp, lp);
}

LRESULT CALLBACK ButtonProc17(HWND settings_ibm, UINT uMsg, WPARAM wp, LPARAM lp)
{
	switch (uMsg) {
	case WM_LBUTTONDOWN:
	{
		int sphinxoutputmode_int(0);
		std::string sphinxoutputmode = loadsphinxoutputfile();
		std::string sphinxoutputmode_temp = loadsphinxoutputtempfile();
		std::ifstream pathfile(sphinxoutputmode);
		pathfile >> sphinxoutputmode_int;
		pathfile.close();

		if (sphinxoutputmode_int == 0)
		{
			std::ofstream mytempfile;
			mytempfile.open(sphinxoutputmode_temp, std::ios::app | std::ios::in);
			mytempfile << 1;
			mytempfile.close();

			char* finalsphinxoutputarray = new char[sphinxoutputmode.length() / sizeof(sphinxoutputmode[0]) + 1];
			char* sphinxoutputtemparray = new char[sphinxoutputmode_temp.length() / sizeof(sphinxoutputmode_temp[0]) + 1];

			for (int count(0); count<sphinxoutputmode.length() / sizeof(sphinxoutputmode[0]); ++count)
			{
				finalsphinxoutputarray[count] = sphinxoutputmode[count];
			}
			finalsphinxoutputarray[sphinxoutputmode.length() / sizeof(sphinxoutputmode[0])] = '\0';
			for (int count(0); count < sphinxoutputmode_temp.length() / sizeof(sphinxoutputmode_temp[0]); ++count)
			{
				sphinxoutputtemparray[count] = sphinxoutputmode_temp[count];
			}
			sphinxoutputtemparray[sphinxoutputmode_temp.length() / sizeof(sphinxoutputmode_temp[0])] = '\0';

			remove(finalsphinxoutputarray);
			rename(sphinxoutputtemparray, finalsphinxoutputarray);

			delete[] finalsphinxoutputarray;
			finalsphinxoutputarray = nullptr;
			delete[] sphinxoutputtemparray;
			sphinxoutputtemparray = nullptr;
		}
		if (sphinxoutputmode_int == 1)
		{
			std::ofstream mytempfile;
			mytempfile.open(sphinxoutputmode_temp, std::ios::app | std::ios::in);
			mytempfile << 0;
			mytempfile.close();

			char* finalsphinxoutputarray = new char[sphinxoutputmode.length() / sizeof(sphinxoutputmode[0]) + 1];
			char* sphinxoutputtemparray = new char[sphinxoutputmode_temp.length() / sizeof(sphinxoutputmode_temp[0]) + 1];

			for (int count(0); count<sphinxoutputmode.length() / sizeof(sphinxoutputmode[0]); ++count)
			{
				finalsphinxoutputarray[count] = sphinxoutputmode[count];
			}
			finalsphinxoutputarray[sphinxoutputmode.length() / sizeof(sphinxoutputmode[0])] = '\0';
			for (int count(0); count < sphinxoutputmode_temp.length() / sizeof(sphinxoutputmode_temp[0]); ++count)
			{
				sphinxoutputtemparray[count] = sphinxoutputmode_temp[count];
			}
			sphinxoutputtemparray[sphinxoutputmode_temp.length() / sizeof(sphinxoutputmode_temp[0])] = '\0';

			remove(finalsphinxoutputarray);
			rename(sphinxoutputtemparray, finalsphinxoutputarray);

			delete[] finalsphinxoutputarray;
			finalsphinxoutputarray = nullptr;
			delete[] sphinxoutputtemparray;
			sphinxoutputtemparray = nullptr;
		}

		MessageBoxA(NULL, "Switching output mode requires restarting LoLvoice. The program will now exit.", "Restart", MB_ICONWARNING | MB_DEFBUTTON2);
		exit(-1);
	}
	break;
	}

	return CallWindowProc(OldButtonProc17, settings_ibm, uMsg, wp, lp);
}

// Functions regarding buttons

// windproc

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	RECT rect;
	int width, height;

	if (GetWindowRect(hwnd, &rect))
	{
		width = (rect.right - rect.left) / 2;
		height = (rect.bottom - rect.top) / 2;
	}

	StateInfo *pState;
	if (uMsg == WM_CREATE)
	{
		CREATESTRUCT *pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
		pState = reinterpret_cast<StateInfo*>(pCreate->lpCreateParams);
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pState);
	}
	else
	{
		pState = GetAppState(hwnd);
	}

	switch (uMsg)
	{
	case WM_CREATE:
	{
#define BUTTON_ID      1001
#define BUTTON_ID_SEC  1002
#define BUTTON_ID_SET  1003

		HWND hButton, hButton2, hButton3;							// Handle for buttons in WM_CREATE

		hButton = CreateWindow(L"button", L"Start",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_BITMAP,
			(width - width*0.8 - width*0.025), (height - height*0.4),
			(width*0.80), (height*0.80),
			hwnd, (HMENU)BUTTON_ID,
			hInst, NULL);

		hButton2 = CreateWindow(L"button", L"Stop",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_BITMAP,
			(width + width*0.025), (height - height*0.4),
			(width*0.80), (height*0.80),
			hwnd, (HMENU)BUTTON_ID_SEC,
			hInst, NULL);

		hButton3 = CreateWindow(L"button", L"Settings",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_BITMAP,
			(width + width*0.70), (height - height*0.95),
			(width*0.20), (height*0.20),
			hwnd, (HMENU)BUTTON_ID_SET,
			hInst, NULL);

		OldButtonProc = (WNDPROC)SetWindowLong(hButton, GWL_WNDPROC, (LONG)ButtonProc);

		OldButtonProc2 = (WNDPROC)SetWindowLong(hButton2, GWL_WNDPROC, (LONG)ButtonProc2);

		OldButtonProc3 = (WNDPROC)SetWindowLong(hButton3, GWL_WNDPROC, (LONG)ButtonProc3);

		SendMessage(GetDlgItem(hwnd, BUTTON_ID), BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap02);
		SendMessage(GetDlgItem(hwnd, BUTTON_ID_SEC), BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap03);
		SendMessage(GetDlgItem(hwnd, BUTTON_ID_SET), BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap04);
	}
		break;

	case WM_SIZING:
	{
	}
	break;

	case WM_DESTROY:
	{
		closeMic();
		miclose();
		closeIbmtts();
		endIbmstt();
		
		DeleteObject(hBitmap01);
		DeleteObject(hBitmap02);
		DeleteObject(hBitmap03);
		DeleteObject(hBitmap04);
		DeleteObject(hBitmap05);

		ShowWindow(windowforsettings, SW_HIDE);

		PostQuitMessage(0);
	}
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		BITMAP          bitmap;
		HDC             hdcMem;
		HGDIOBJ         oldBitmap;

		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hBitmap01);

		GetObject(hBitmap01, sizeof(bitmap), &bitmap);
		BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);

		if (isIbm == true)
		{
			if (checkforhandlenull())
			{
				MessageBoxA(NULL, "Failed to initiate IBM-STT. IBM-STT cannot be used unless you provide a correct username and password.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
			}
		}
		if (isSphinx == true)
		{
			if (checkifsphinxfilesnotloaded())
			{
				MessageBoxA(NULL, "Failed to load sphinx files. Sphinx cannot be used.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
			}
		}
		if (isOverdrive == true)
		{
			if (checkforhandlenull())
			{
				MessageBoxA(NULL, "Failed to initiate IBM-STT. IBM-STT cannot be used unless you provide a correct username and password.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
			}
			if (checkifsphinxfilesnotloaded())
			{
				MessageBoxA(NULL, "Failed to load sphinx files. Sphinx cannot be used.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
			}
		}

		EndPaint(hwnd, &ps);
	}
	break;

	case WM_ERASEBKGND:
	{
		return (LRESULT)1;
	}
	break;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK WindowProc_set(HWND settings, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rect_set;
	int width_set, height_set;

	if (GetWindowRect(settings, &rect_set))
	{
		width_set = (rect_set.right - rect_set.left) / 2;
		height_set = (rect_set.bottom - rect_set.top) / 2;
	}

	switch (uMsg)
	{
	case WM_CREATE:
	{
#define BUTTON_ID_OK 1004
#define BUTTON_ID_KEY 1005
#define BUTTON_ID_SPLIT 1006
#define BUTTON_ID_ADAPT 1007
#define BUTTON_ID_ADAPTCONT 1008
#define BUTTON_ID_ADAPTCONT2 1009

		HWND okButton, keyButton;

		HWND address_input = CreateWindowExA(WS_EX_CLIENTEDGE, "edit", "...",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
			(width_set - width_set*0.95), (height_set - height_set*0.85), 200, 24,	// x, y, w, h
			settings, (HMENU)(101),
			hinst_set, NULL);

		okButton = CreateWindow(L"button", L"Set Path",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			(width_set + width_set*0.50), (height_set - height_set*0.85),
			(width_set*0.40), 24,
			settings, (HMENU)BUTTON_ID_OK,
			hinst_set, NULL);

		keyButton = CreateWindow(L"button", L"Change",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			(width_set + width_set*0.50), (height_set - height_set*0.55 + height_set*0.10),
			(width_set*0.40), 24,
			settings, (HMENU)BUTTON_ID_KEY,
			hinst_set, NULL);

		HWND adaptButton = CreateWindow(L"button", L"Start",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			(width_set - width_set * 0.40), (height_set + height_set*0.15),
			(width_set*0.80), (height_set*0.20),
			settings, (HMENU)BUTTON_ID_ADAPT,
			hinst_set, NULL);

		HWND adaptButton_cont = CreateWindow(L"button", L"Continue",
			WS_CHILD | BS_DEFPUSHBUTTON,
			(width_set - width_set * 0.40), (height_set + height_set*0.15),
			(width_set*0.80), (height_set*0.20),
			settings, (HMENU)BUTTON_ID_ADAPTCONT,
			hinst_set, NULL);

		HWND adaptButton_cont2 = CreateWindow(L"button", L"Begin",
			WS_CHILD | BS_DEFPUSHBUTTON,
			(width_set - width_set * 0.40), (height_set + height_set*0.15),
			(width_set*0.80), (height_set*0.20),
			settings, (HMENU)BUTTON_ID_ADAPTCONT2,
			hinst_set, NULL);

		LPCTSTR keybind = intToKey(viewKey());

		HWND keybindscreen = CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", keybind,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
			(width_set - width_set*0.95), (height_set - height_set*0.55 + height_set*0.10), (width_set*0.60), 24,	// x, y, w, h
			settings, (HMENU)(101),
			hinst_set, NULL);

		HWND adaptscreen = CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"Press 'Start' to begin",
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
			(width_set - width_set * 0.99), (height_set + height_set*0.375), (width_set + width_set*0.90), 50,	// x, y, w, h
			settings, (HMENU)(101),
			hinst_set, NULL);

		int sphinxoutputmode_int(0);
		std::string sphinxoutputmode = loadsphinxoutputfile();
		std::ifstream pathfile(sphinxoutputmode);
		pathfile >> sphinxoutputmode_int;
		pathfile.close();

		if (sphinxoutputmode_int == 0)
		{
			HWND sphinxoutputmodescreen = CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"Block",
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
				(width_set - width_set*0.95), (height_set + height_set*0.05 - 25),
				(width_set*0.60), 24,	// x, y, w, h
				settings, (HMENU)(101),
				hinst_set, NULL);
		}
		if (sphinxoutputmode_int == 1)
		{
			HWND sphinxoutputmodescreen = CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"Spread",
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
				(width_set - width_set*0.95), (height_set + height_set*0.05 - 25),
				(width_set*0.60), 24,	// x, y, w, h
				settings, (HMENU)(101),
				hinst_set, NULL);
		}

		HWND switchoutputButton = CreateWindow(L"button", L"Switch",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			(width_set + width_set*0.50), (height_set + height_set*0.05 - 25),
			(width_set*0.40), 24,
			settings, (HMENU)BUTTON_ID_KEY,
			hinst_set, NULL);

		OldButtonProc4 = (WNDPROC)SetWindowLong(okButton, GWL_WNDPROC, (LONG)ButtonProc4);

		OldButtonProc5 = (WNDPROC)SetWindowLong(keyButton, GWL_WNDPROC, (LONG)ButtonProc5);

		OldButtonProc6 = (WNDPROC)SetWindowLong(adaptButton, GWL_WNDPROC, (LONG)ButtonProc6);

		OldButtonProc7 = (WNDPROC)SetWindowLong(adaptButton_cont, GWL_WNDPROC, (LONG)ButtonProc7);

		OldButtonProc8 = (WNDPROC)SetWindowLong(adaptButton_cont2, GWL_WNDPROC, (LONG)ButtonProc8);

		OldButtonProc17 = (WNDPROC)SetWindowLong(switchoutputButton, GWL_WNDPROC, (LONG)ButtonProc17);

		GetWindowLong(settings, GWL_HINSTANCE);

		setwindow = FindWindowEx(
			settings,
			NULL,
			L"edit",
			L"..."
		);

		setkeybind = FindWindowEx(
			settings,
			NULL,
			L"Static",
			keybind
		);

		adaptchange = FindWindowEx(
			settings,
			NULL,
			L"Static",
			L"Press 'Start' to begin"
		);

		adaptbutton = FindWindowEx(
			settings,
			NULL,
			L"button",
			L"Start"
		);

		adaptbuttoncont = FindWindowEx(
			settings,
			NULL,
			L"button",
			L"Continue"
		);

		adaptbuttoncont2 = FindWindowEx(
			settings,
			NULL,
			L"button",
			L"Begin"
		);
	}
	break;

	case WM_SIZING:
	{

	}
	break;

	case WM_DESTROY:
		settingsFocus = true;
		if (psChecker())
		{
			Sleep(2*1000);
			if (psChecker())
			{
				MessageBoxA(NULL, "Error Loading Path.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
			}
		}
		break;

	case WM_CTLCOLOREDIT:
	{
		HDC hdcEdit = (HDC)wParam;
		SetTextColor(hdcEdit, RGB(236, 201, 94));
		SetBkColor(hdcEdit, RGB(56, 56, 56));
		return (INT_PTR)CreateSolidBrush(RGB(56, 56, 56));
	}
		break;

	case WM_CTLCOLORSTATIC:
	{
		HDC hdcEdit = (HDC)wParam;
		SetTextColor(hdcEdit, RGB(236, 201, 94));
		SetBkColor(hdcEdit, RGB(56, 56, 56));
		return (INT_PTR)CreateSolidBrush(RGB(56, 56, 56));
	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(settings, &ps);
		BITMAP          bitmap;
		HDC             hdcMem;
		HGDIOBJ         oldBitmap;	

		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hBitmap05);

		GetObject(hBitmap05, sizeof(bitmap), &bitmap);
		BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);

		LPSTR TextArray[] = {
			"LoLvoice.exe Directory"
		};

		LPSTR adaptText[] = {
			"Adapt voice to LoLvoice"
		};

		LPSTR keybindText[] = {
			"Keybind"
		};

		LPSTR outputmodeText[] = {
			"Output mode"
		};

		COLORREF crColor = RGB(
			223,
			225,
			223
		);

		COLORREF crColor_back = RGB(
			0,
			0,
			0
		);

		SetTextColor(
			hdc,
			crColor
		);

		SetBkColor(
			hdc,
			crColor_back
		);

		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set - height_set*0.975),
			TextArray[0],
			23
		);

		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set + height_set*0.05),
			adaptText[0],
			24
		);

		
		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set - height_set*0.575),
			keybindText[0],
			8
		);

		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set + height_set*0.05 - 45),
			outputmodeText[0],
			12
		);

		EndPaint(settings, &ps);
	}
	return 0;

	}
	return DefWindowProc(settings, uMsg, wParam, lParam);
}

LRESULT CALLBACK WindowProc_ibm(HWND settings_ibm, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rect_set;
	int width_set, height_set;

	if (GetWindowRect(settings_ibm, &rect_set))
	{
		width_set = (rect_set.right - rect_set.left) / 2;
		height_set = (rect_set.bottom - rect_set.top) / 2;
	}

	switch (uMsg)
	{
	case WM_CREATE:
	{
#define BUTTON_ID_USERPASS 1015
		username = CreateWindowExA(WS_EX_CLIENTEDGE, "edit", "",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
			(width_set - width_set*0.95), (height_set - height_set*0.85), 200, 24,	// x, y, w, h
			settings_ibm, (HMENU)(101),
			hinst_ibm, NULL);

		password = CreateWindowExA(WS_EX_CLIENTEDGE, "edit", "",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
			(width_set - width_set*0.95), (height_set - height_set*0.55 + height_set*0.10), 200, 24,	// x, y, w, h
			settings_ibm, (HMENU)(101),
			hinst_ibm, NULL);

		setuserpassButton = CreateWindow(L"button", L"Confirm",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			(width_set - (width_set*0.80)/2), (height_set - height_set*0.55 + height_set*0.35),
			(width_set*0.80), 24,
			settings_ibm, (HMENU)BUTTON_ID_USERPASS,
			hinst_ibm, NULL);

		HWND instructionButton = CreateWindow(L"button", L"Create account",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_MULTILINE,
			(width_set + width_set*0.30), (height_set - 110),
			(width_set*0.40), 50,
			settings_ibm, (HMENU)BUTTON_ID_USERPASS,
			hinst_ibm, NULL);

		HWND keyButton = CreateWindow(L"button", L"Change",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			(width_set + width_set*0.50), (height_set + 50 - 30),
			(width_set*0.40), 24,
			settings_ibm, (HMENU)BUTTON_ID_KEY,
			hinst_ibm, NULL);

		LPCTSTR keybind = intToKey(viewKey());

		HWND keybindscreen = CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", keybind,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
			(width_set - width_set*0.95), (height_set + 50 - 30), 
			(width_set*0.60), 24,	// x, y, w, h
			settings_ibm, (HMENU)(101),
			hinst_ibm, NULL);

		int ibmoutputmode_int(0);
		std::string ibmoutputmode = loadibmoutputfile();
		std::ifstream pathfile(ibmoutputmode);
		pathfile >> ibmoutputmode_int;
		pathfile.close();

		if (ibmoutputmode_int == 0)
		{
			HWND ibmoutputmodescreen = CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"Block",
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
				(width_set - width_set*0.95), (height_set + 50 + 20),
				(width_set*0.60), 24,	// x, y, w, h
				settings_ibm, (HMENU)(101),
				hinst_ibm, NULL);
		}
		if (ibmoutputmode_int == 1)
		{
			HWND ibmoutputmodescreen = CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", L"Spread",
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
				(width_set - width_set*0.95), (height_set + 50 + 20),
				(width_set*0.60), 24,	// x, y, w, h
				settings_ibm, (HMENU)(101),
				hinst_ibm, NULL);
		}

		HWND switchoutputButton = CreateWindow(L"button", L"Switch",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			(width_set + width_set*0.50), (height_set + 50 + 20),
			(width_set*0.40), 24,
			settings_ibm, (HMENU)BUTTON_ID_KEY,
			hinst_ibm, NULL);

		OldButtonProc5 = (WNDPROC)SetWindowLong(keyButton, GWL_WNDPROC, (LONG)ButtonProc5);
		OldButtonProc13 = (WNDPROC)SetWindowLong(setuserpassButton, GWL_WNDPROC, (LONG)ButtonProc13);
		OldButtonProc14 = (WNDPROC)SetWindowLong(instructionButton, GWL_WNDPROC, (LONG)ButtonProc14);
		OldButtonProc16 = (WNDPROC)SetWindowLong(switchoutputButton, GWL_WNDPROC, (LONG)ButtonProc16);

		GetWindowLong(settings_ibm, GWL_HINSTANCE);

		setkeybind = FindWindowEx(
			settings_ibm,
			NULL,
			L"Static",
			keybind
		);
	}
	break;

	case WM_SIZING:
	{

	}
	break;

	case WM_DESTROY:
		settingsFocus_ibm = true;
		break;

	case WM_CTLCOLOREDIT:
	{
		HDC hdcEdit = (HDC)wParam;
		SetTextColor(hdcEdit, RGB(236, 201, 94));
		SetBkColor(hdcEdit, RGB(56, 56, 56));
		return (INT_PTR)CreateSolidBrush(RGB(56, 56, 56));
	}
	break;

	case WM_CTLCOLORSTATIC:
	{
		HDC hdcEdit = (HDC)wParam;
		SetTextColor(hdcEdit, RGB(236, 201, 94));
		SetBkColor(hdcEdit, RGB(56, 56, 56));
		return (INT_PTR)CreateSolidBrush(RGB(56, 56, 56));
	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(settings_ibm, &ps);
		BITMAP          bitmap;
		HDC             hdcMem;
		HGDIOBJ         oldBitmap;

		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hBitmap05);

		GetObject(hBitmap05, sizeof(bitmap), &bitmap);
		BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);

		LPSTR userArray[] = {
			"Username"
		};

		LPSTR passText[] = {
			"Password"
		};

		LPSTR keybindText[] = {
			"Keybind"
		};

		LPSTR ibmoutputmodesText[] = {
			"Output mode"
		};

		COLORREF crColor = RGB(
			223,
			225,
			223
		);

		COLORREF crColor_back = RGB(
			0,
			0,
			0
		);

		SetTextColor(
			hdc,
			crColor
		);

		SetBkColor(
			hdc,
			crColor_back
		);

		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set - height_set*0.975),
			userArray[0],
			9
		);

		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set - height_set*0.575),
			passText[0],
			9
		);

		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set + 30 - 30),
			keybindText[0],
			8
		);

		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set + 50),
			ibmoutputmodesText[0],
			12
		);

		EndPaint(settings_ibm, &ps);
	}
	return 0;

	}
	return DefWindowProc(settings_ibm, uMsg, wParam, lParam);
}

LRESULT CALLBACK WindowProc_overdrive(HWND settings_overdrive, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rect_set;
	int width_set, height_set;

	if (GetWindowRect(settings_overdrive, &rect_set))
	{
		width_set = (rect_set.right - rect_set.left) / 2;
		height_set = (rect_set.bottom - rect_set.top) / 2;
	}

	switch (uMsg)
	{
	case WM_CREATE:
	{
#define BUTTON_ID_OVERDRIVE 1016
		HWND overdriveButton = CreateWindow(L"button", L"Set IBMSTT key",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			(width_set + width_set*0.10), (height_set + 50),
			(width_set*0.80), 24,
			settings_overdrive, (HMENU)BUTTON_ID_OVERDRIVE,
			hinst_overdrive, NULL);

		LPCTSTR keybind_overdrive = intToKey(viewOverdriveKey());

		HWND keybindscreen = CreateWindowEx(WS_EX_CLIENTEDGE, L"Static", keybind_overdrive,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
			(width_set - width_set*0.95), (height_set + 50),
			(width_set*0.60), 24,	// x, y, w, h
			settings_overdrive, (HMENU)(101),
			hinst_overdrive, NULL);

		OldButtonProc15 = (WNDPROC)SetWindowLong(overdriveButton, GWL_WNDPROC, (LONG)ButtonProc15);

		GetWindowLong(settings_overdrive, GWL_HINSTANCE);

		setoverdrivebind = FindWindowEx(
			settings_overdrive,
			NULL,
			L"Static",
			keybind_overdrive
		);
	}
	break;

	case WM_SIZING:
	{

	}
	break;

	case WM_DESTROY:
		settingsFocus_overdrive = true;
		break;

	case WM_CTLCOLOREDIT:
	{
		HDC hdcEdit = (HDC)wParam;
		SetTextColor(hdcEdit, RGB(236, 201, 94));
		SetBkColor(hdcEdit, RGB(56, 56, 56));
		return (INT_PTR)CreateSolidBrush(RGB(56, 56, 56));
	}
	break;

	case WM_CTLCOLORSTATIC:
	{
		HDC hdcEdit = (HDC)wParam;
		SetTextColor(hdcEdit, RGB(236, 201, 94));
		SetBkColor(hdcEdit, RGB(56, 56, 56));
		return (INT_PTR)CreateSolidBrush(RGB(56, 56, 56));
	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(settings_overdrive, &ps);
		BITMAP          bitmap;
		HDC             hdcMem;
		HGDIOBJ         oldBitmap;

		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hBitmap05);

		GetObject(hBitmap05, sizeof(bitmap), &bitmap);
		BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);

		char overdriveText[] = "To change the settings of Sphinx or IBM-STT, go to their individual settings. To use Overdrive, the keybind for Sphinx remains the same while the keybind for IBM_STT can be set below.";
	

		LPSTR keybindText[] = {
			"Keybind"
		};

		COLORREF crColor = RGB(
			223,
			225,
			223
		);

		COLORREF crColor_back = RGB(
			0,
			0,
			0
		);

		SetTextColor(
			hdc,
			crColor
		);

		SetBkColor(
			hdc,
			crColor_back
		);

		TextOutA(
			hdc,
			(width_set - width_set*0.95),
			(height_set + 30),
			keybindText[0],
			8
		);
		RECT rc_overdrive;
		SetRect(&rc_overdrive, (width_set - width_set*0.85), (height_set - height_set*0.80), 375, 450);
		DrawTextA(hdc, overdriveText, ::strlen(overdriveText), &rc_overdrive, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
		ReleaseDC(0, hdc);

		EndPaint(settings_overdrive, &ps);
	}
	return 0;

	}
	return DefWindowProc(settings_overdrive, uMsg, wParam, lParam);
}

LRESULT CALLBACK WindowProc_path(HWND hwnd_path, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	RECT rect;
	int width_path, height_path;

	if (GetWindowRect(hwnd_path, &rect))
	{
		width_path = (rect.right - rect.left) / 2;
		height_path = (rect.bottom - rect.top) / 2;
	}

	switch (uMsg)
	{
	case WM_CREATE:
	{
#define PATH_INPUT 1010
#define BUTTON_ID_PATH 1011
		
		char* defaultpath = nullptr;
		int defaultpathlength(0);
		createPathtoExeDirectory(defaultpath, defaultpathlength);

		path_input = CreateWindowExA(WS_EX_CLIENTEDGE, "edit", defaultpath,
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
			(width_path - width_path*0.95), (height_path - 35), 400, 24,	// x, y, w, h
			hwnd_path, (HMENU)PATH_INPUT,
			hinst_path, NULL);

		 pathButton = CreateWindow(L"button", L"Set Path",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_CENTER | BS_MULTILINE,
			(width_path + width_path*0.50), (height_path-60),
			(width_path*0.40), 100,
			hwnd_path, (HMENU)BUTTON_ID_PATH,
			hinst_path, NULL);

		OldButtonProc9 = (WNDPROC)SetWindowLong(pathButton, GWL_WNDPROC, (LONG)ButtonProc9);
		delete[] defaultpath;
		defaultpath = nullptr;
	}
	break;

	case WM_SIZING:
	{

	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		exit(1);
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd_path, &ps);
		BITMAP          bitmap;
		HDC             hdcMem;
		HGDIOBJ         oldBitmap;

		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hBitmap01);

		GetObject(hBitmap01, sizeof(bitmap), &bitmap);
		BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);

		LPSTR Directorytext[] = {
			"LoLvoice.exe Directory:"
		};

		COLORREF crColor = RGB(
			255,
			255,
			255
		);

		COLORREF crColor_back = RGB(
			22,
			45,
			77
		);

		SetTextColor(
			hdc,
			crColor
		);

		SetBkMode(
			hdc,
			TRANSPARENT
		);

		TextOutA(
			hdc,
			(width_path - width_path*0.95),
			(height_path - height_path*0.55),
			Directorytext[0],
			24
		);

		EndPaint(hwnd_path, &ps);
	}
	return 0;

	}
	return DefWindowProc(hwnd_path, uMsg, wParam, lParam);
}

LRESULT CALLBACK WindowProc_speech(HWND hwnd_speech, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	RECT rect;
	int width_path, height_path;

	if (GetWindowRect(hwnd_speech, &rect))
	{
		width_path = (rect.right - rect.left) / 2;
		height_path = (rect.bottom - rect.top) / 2;
	}

	switch (uMsg)
	{
	case WM_CREATE:
	{
#define BUTTON_ID_SPHINX 1012
#define BUTTON_ID_IBM 1013
#define BUTTON_ID_COMBINE 1014

		HWND sphinxButton = CreateWindow(L"button", L"Sphinx",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_BITMAP,
			(width_path - width_path*0.90), (height_path - width_path*1.15),
			(width_path*0.65), (width_path*0.65),
			hwnd_speech, (HMENU)BUTTON_ID_SPHINX,
			hinst_speech, NULL);

		HWND ibmButton = CreateWindow(L"button", L"IBM-TTS",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_BITMAP,
			(width_path - width_path*0.90), (height_path - width_path*0.40),
			(width_path*0.65), (width_path*0.65),
			hwnd_speech, (HMENU)BUTTON_ID_IBM,
			hinst_speech, NULL);

		// combine both sphinx and ibm
		HWND combineButton = CreateWindow(L"button", L"Overdrive",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_BITMAP,
			(width_path - width_path*0.90), (height_path + width_path*0.35),
			(width_path*0.65), (width_path*0.65),
			hwnd_speech, (HMENU)BUTTON_ID_COMBINE,
			hinst_speech, NULL);

		OldButtonProc10 = (WNDPROC)SetWindowLong(sphinxButton, GWL_WNDPROC, (LONG)ButtonProc10);
		OldButtonProc11 = (WNDPROC)SetWindowLong(ibmButton, GWL_WNDPROC, (LONG)ButtonProc11);
		OldButtonProc12 = (WNDPROC)SetWindowLong(combineButton, GWL_WNDPROC, (LONG)ButtonProc12);

		SendMessage(sphinxButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap06);
		SendMessage(ibmButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap07);
		SendMessage(combineButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap08);
	}
	break;

	case WM_SIZING:
	{

	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		exit(-1);
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd_speech, &ps);
		BITMAP          bitmap;
		HDC             hdcMem;
		HGDIOBJ         oldBitmap;

		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hBitmap01);

		GetObject(hBitmap01, sizeof(bitmap), &bitmap);
		BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);

		RECT rc_sphinx;
		char sphinx_intro[] = "- Accuracy varies from person\n to person\n- Mediocre speed\n- High CPU usage\n- Contains LOL specific words\n- Can adapt to your voice\nthrough adaption\n- Unlimited usage\n\n\n\
- High accuracy\n- High speed\n- Better suited for long\n sentences\n- Limited usage\n- Requires a free IBM-TTS account\n\n\n- Combines both Sphinx and IBM-TTS\n- Memory intensive\n- Harder to use";

		COLORREF crColor = RGB(
			255,
			255,
			255
		);

		COLORREF crColor_back = RGB(
			22,
			45,
			77
		);

		SetTextColor(
			hdc,
			crColor
		);

		SetBkMode(
			hdc,
			TRANSPARENT
		);

		SetRect(&rc_sphinx, (width_path - width_path*0.10),(height_path - width_path*1.15), 400, 450);
		DrawTextA(hdc, sphinx_intro, ::strlen(sphinx_intro), &rc_sphinx, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
		ReleaseDC(0, hdc);

		EndPaint(hwnd_speech, &ps);
	}
	return 0;

	}
	return DefWindowProc(hwnd_speech, uMsg, wParam, lParam);
}

void recordsoundfiles(const LPWSTR filename, const LPWSTR nextline)
{
	char storage[16] = "\\adapt\\records\\";

	char* fullnamepath = nullptr;
	fullnamepath = new char[len + 15 + 15 + 1];

	for (int count(0); count < len; ++count)
	{
		fullnamepath[count] = folderPathstr[count];
	}
	for (int count(0); count < 15; ++count)
	{
		fullnamepath[count + len] = storage[count];
	}
	for (int count(0); count < 15; ++count)
	{
		fullnamepath[count + len + 15] = filename[count];
	}
	fullnamepath[len + 15 + 15] = '\0';
	size_t sizechary = strlen(fullnamepath) + 1;
	size_t outSize;
	wchar_t* wtext = new wchar_t[sizechary];

	mbstowcs_s(&outSize, wtext, sizechary, fullnamepath, sizechary-1);
	LPWSTR ptr = wtext;

		// button
		SetWindowText(
			adaptbuttoncont2,
			L"Press 'S' to stop"
		);
		// record
		setrecordname(ptr);
		std::thread recording(startRecording);
		recording.join();
		// button
		SetWindowText(
			adaptbuttoncont2,
			L" "
		);
		// output
		SetWindowText(
			adaptchange,
			L"Saved. Onto the next sentence"
		);
		Sleep(3 * 1000);
		// button
		SetWindowText(
			adaptbuttoncont2,
			L"Record"
		);
		// output
		SetWindowText(
			adaptchange,
			nextline
		);

		delete[] fullnamepath;
		fullnamepath = nullptr;
		delete[] wtext;
		wtext = nullptr;
}

void recordlastsoundfiles(const LPWSTR filename)
{
	char storage[16] = "\\adapt\\records\\";

	char* fullnamepath = nullptr;
	fullnamepath = new char[len + 15 + 15 + 1];

	for (int count(0); count < len; ++count)
	{
		fullnamepath[count] = folderPathstr[count];
	}
	for (int count(0); count < 15; ++count)
	{
		fullnamepath[count + len] = storage[count];
	}
	for (int count(0); count < 15; ++count)
	{
		fullnamepath[count + len + 15] = filename[count];
	}
	fullnamepath[len + 15 + 15] = '\0';
	size_t sizechary = strlen(fullnamepath) + 1;
	size_t outSize;
	wchar_t* wtext = new wchar_t[sizechary];

	mbstowcs_s(&outSize, wtext, sizechary, fullnamepath, sizechary - 1);
	LPWSTR ptr = wtext;

	// button
	SetWindowText(
		adaptbuttoncont2,
		L"Press 'S' to stop"
	);
	// record
	setrecordname(ptr);
	std::thread recording(startRecording);
	recording.join();
	// button
	SetWindowText(
		adaptbuttoncont2,
		L" "
	);
	// output
	SetWindowText(
		adaptchange,
		L"Saved. That is the last one."
	);
	std::thread initializingpaths(initializePaths);
	initializingpaths.join();

	renamefolder("\\en-us", 6, "\\en-us-deprecated", 17);
	renamefolder("\\en-us-adapt", 12, "\\en-us", 6);
	renamefolder("\\en-us-deprecated", 17, "\\en-us-adapt", 12);

	Sleep(3 * 1000);
	// button
	SetWindowText(
		adaptbuttoncont2,
		L"Redo"
	);
	// output
	SetWindowText(
		adaptchange,
		L"Press 'Redo' to adapt again"
	);

	delete[] fullnamepath;
	fullnamepath = nullptr;
	delete[] wtext;
	wtext = nullptr;
}

void renamefolder(const char* oldname, const int sizeofoldname, const char* newname, const int sizeofnewname)
{
	char* renamename = nullptr;
	renamename = new char[len + sizeofoldname + 1];

	for (int count(0); count < len; ++count)
	{
		renamename[count] = folderPathstr[count];
	}
	for (int count(0); count < sizeofoldname; ++count)
	{
		renamename[count + len] = oldname[count];
	}
	renamename[len + sizeofoldname] = '\0';

	char* renamenewname = nullptr;
	renamenewname = new char[len + sizeofnewname + 1];

	for (int count(0); count < len; ++count)
	{
		renamenewname[count] = folderPathstr[count];
	}
	for (int count(0); count < sizeofnewname; ++count)
	{
		renamenewname[count + len] = newname[count];
	}
	renamenewname[len + sizeofnewname] = '\0';

	// rename folder here
	int result;
	result = rename(renamename, renamenewname);
	if (result == 0);
		// check
	else;
		// check

	delete[] renamename;
	renamename = nullptr;
	delete[] renamenewname;
	renamenewname = nullptr;
}

void loadbitmaps(char* bitnameptr, const char* bitname, const int sizeofbitname)
{
	for (int count(0); count < len; ++count)
	{
		bitnameptr[count] = folderPathstr[count];
	}
	for (int count(0); count < sizeofbitname; ++count)
	{
		bitnameptr[len + count] = bitname[count];
	}
	bitnameptr[len + sizeofbitname] = '\0';
}

void loadbitmaps_default(char* bitnameptr, const char* bitname, const int sizeofbitname)
{
	for (int count(0); count < len-1; ++count)
	{
		bitnameptr[count] = folderPathstr[count];
	}
	for (int count(0); count < sizeofbitname; ++count)
	{
		bitnameptr[len + count - 1] = bitname[count];
	}
	bitnameptr[len + sizeofbitname - 1] = '\0';
}

void loadVariablesWindow()
{
	// LoLvoice.exe path
	configfinalpath = loadconfigfile();
	std::string line;
	std::ifstream myfile(configfinalpath);
	int sizee(0);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			sizee = line.length() - 1;
			folderPath = new char[sizee - 25];
			for (int count(0); count < (sizee - 25); ++count)
			{
				folderPath[count] = line[count + 25];
			}
		}
		myfile.close();
	}

	// config files
	configtempfinalpath = loadconfigtempfile();
	configinifinalpath = loadconfiginifile();

	// check for error with loading images, if error then show path window
	len = returnSizee();
	folderPathstr = sconvert(folderPath, len);

	if (checkiffoldersexist(folderPathstr) == false)
	{
		// when the path is not valid
		char* defaultpath = nullptr;
		createPathtoExeDirectory(defaultpath, len);
		folderPathstr = sconvert(defaultpath, (len-1));

		std::string finalpath = loadpathfile();
		std::string pathtemp = loadpathtempfile();

		std::string templine;
		std::ofstream mytempfile;
		mytempfile.open(pathtemp, std::ios::app | std::ios::in);
		mytempfile << 0;
		mytempfile.close();

		char* finalpatharray = new char[finalpath.length() / sizeof(finalpath[0]) + 1];
		char* finaltemppatharray = new char[pathtemp.length() / sizeof(pathtemp[0]) + 1];

		for (int count(0); count < finalpath.length() / sizeof(finalpath[0]); ++count)
		{
			finalpatharray[count] = finalpath[count];
		}
		finalpatharray[finalpath.length() / sizeof(finalpath[0])] = '\0';
		for (int count(0); count < pathtemp.length() / sizeof(pathtemp[0]); ++count)
		{
			finaltemppatharray[count] = pathtemp[count];
		}
		finaltemppatharray[pathtemp.length() / sizeof(pathtemp[0])] = '\0';

		remove(finalpatharray);
		rename(finaltemppatharray, finalpatharray);

		delete[] finalpatharray;
		finalpatharray = nullptr;
		delete[] finaltemppatharray;
		finaltemppatharray = nullptr;
		delete[] defaultpath;
		defaultpath = nullptr;

		// vector files
		char gearimage[17] = "/Vector/gear.bmp";
		gearbmp = new char[len + 16 + 1];
		loadbitmaps_default(gearbmp, gearimage, 16);
		hBitmap04 = (HBITMAP)LoadImageA(NULL, gearbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] gearbmp;
		gearbmp = nullptr;

		char lmageimage[18] = "/Vector/lmage.bmp";
		lmagebmp = new char[len + 17 + 1];
		loadbitmaps_default(lmagebmp, lmageimage, 17);
		hBitmap02 = (HBITMAP)LoadImageA(NULL, lmagebmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] lmagebmp;
		lmagebmp = nullptr;

		char lmage_stopimage[23] = "/Vector/lmage_stop.bmp";
		lmage_stopbmp = new char[len + 22 + 1];
		loadbitmaps_default(lmage_stopbmp, lmage_stopimage, 22);
		hBitmap03 = (HBITMAP)LoadImageA(NULL, lmage_stopbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] lmage_stopbmp;
		lmage_stopbmp = nullptr;

		char imageimage[18] = "/Vector/image.bmp";
		imagebmp = new char[len + 17 + 1];
		loadbitmaps_default(imagebmp, imageimage, 17);
		hBitmap01 = (HBITMAP)LoadImageA(NULL, imagebmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] imagebmp;
		imagebmp = nullptr;

		char groundimage[19] = "/Vector/ground.bmp";
		groundbmp = new char[len + 18 + 1];
		loadbitmaps_default(groundbmp, groundimage, 18);
		hBitmap05 = (HBITMAP)LoadImageA(NULL, groundbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] groundbmp;
		groundbmp = nullptr;

		char sphinximage[24] = "/Vector/imagesphinx.bmp";
		sphinxbmp = new char[len + 23 + 1];
		loadbitmaps_default(sphinxbmp, sphinximage, 23);
		hBitmap06 = (HBITMAP)LoadImageA(NULL, sphinxbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] sphinxbmp;
		sphinxbmp = nullptr;

		char ibmsttimage[19] = "/Vector/ibmstt.bmp";
		ibmsttbmp = new char[len + 18 + 1];
		loadbitmaps_default(ibmsttbmp, ibmsttimage, 18);
		hBitmap07 = (HBITMAP)LoadImageA(NULL, ibmsttbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] ibmsttbmp;
		ibmsttbmp = nullptr;

		char overdriveimage[22] = "/Vector/overdrive.bmp";
		overdrivebmp = new char[len + 21 + 1];
		loadbitmaps_default(overdrivebmp, overdriveimage, 21);
		hBitmap08 = (HBITMAP)LoadImageA(NULL, overdrivebmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] overdrivebmp;
		overdrivebmp = nullptr;
	}
	else
	{
		// when the path is valid
		len = returnSizee();
		folderPathstr = sconvert(folderPath, len);

		// vector files
		char gearimage[17] = "/Vector/gear.bmp";
		gearbmp = new char[len + 16 + 1];
		loadbitmaps(gearbmp, gearimage, 16);
		hBitmap04 = (HBITMAP)LoadImageA(NULL, gearbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] gearbmp;
		gearbmp = nullptr;

		char lmageimage[18] = "/Vector/lmage.bmp";
		lmagebmp = new char[len + 17 + 1];
		loadbitmaps(lmagebmp, lmageimage, 17);
		hBitmap02 = (HBITMAP)LoadImageA(NULL, lmagebmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] lmagebmp;
		lmagebmp = nullptr;

		char lmage_stopimage[23] = "/Vector/lmage_stop.bmp";
		lmage_stopbmp = new char[len + 22 + 1];
		loadbitmaps(lmage_stopbmp, lmage_stopimage, 22);
		hBitmap03 = (HBITMAP)LoadImageA(NULL, lmage_stopbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] lmage_stopbmp;
		lmage_stopbmp = nullptr;

		char imageimage[18] = "/Vector/image.bmp";
		imagebmp = new char[len + 17 + 1];
		loadbitmaps(imagebmp, imageimage, 17);
		hBitmap01 = (HBITMAP)LoadImageA(NULL, imagebmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] imagebmp;
		imagebmp = nullptr;

		char groundimage[19] = "/Vector/ground.bmp";
		groundbmp = new char[len + 18 + 1];
		loadbitmaps(groundbmp, groundimage, 18);
		hBitmap05 = (HBITMAP)LoadImageA(NULL, groundbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] groundbmp;
		groundbmp = nullptr;

		char sphinximage[24] = "/Vector/imagesphinx.bmp";
		sphinxbmp = new char[len + 23 + 1];
		loadbitmaps(sphinxbmp, sphinximage, 23);
		hBitmap06 = (HBITMAP)LoadImageA(NULL, sphinxbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] sphinxbmp;
		sphinxbmp = nullptr;

		char ibmsttimage[19] = "/Vector/ibmstt.bmp";
		ibmsttbmp = new char[len + 18 + 1];
		loadbitmaps(ibmsttbmp, ibmsttimage, 18);
		hBitmap07 = (HBITMAP)LoadImageA(NULL, ibmsttbmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] ibmsttbmp;
		ibmsttbmp = nullptr;

		char overdriveimage[22] = "/Vector/overdrive.bmp";
		overdrivebmp = new char[len + 21 + 1];
		loadbitmaps(overdrivebmp, overdriveimage, 21);
		hBitmap08 = (HBITMAP)LoadImageA(NULL, overdrivebmp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		delete[] overdrivebmp;
		overdrivebmp = nullptr;
	}

	if (hBitmap01 == NULL)
		MessageBoxA(NULL, "Error Loading image.bmp.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	if (hBitmap02 == NULL)
		MessageBoxA(NULL, "Error Loading lmage.bmp.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	if (hBitmap03 == NULL)
		MessageBoxA(NULL, "Error Loading lmage_stop.bmp.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	if (hBitmap04 == NULL)
		MessageBoxA(NULL, "Error Loading gear.bmp.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	if (hBitmap05 == NULL)
		MessageBoxA(NULL, "Error Loading ground.bmp.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	if (hBitmap06 == NULL)
		MessageBoxA(NULL, "Error Loading sphinx.bmp.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	if (hBitmap07 == NULL)
		MessageBoxA(NULL, "Error Loading ibmstt.bmp.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
}

std::string loadpathfile()
{
	// load config
	char exe_path[MAX_PATH];
	char* path_path = nullptr;
	HMODULE hmodule = GetModuleHandle(NULL);
	GetModuleFileNameA(hmodule, exe_path, (sizeof(exe_path)));
	int directorysize(0);

	for (int count(0); count < 260; ++count)
	{
		++directorysize;
		// find LoLvoice.exe
		if (exe_path[count] == 'L')
		{
			if (exe_path[count + 1] == 'o')
			{
				if (exe_path[count + 2] == 'L')
				{
					if (exe_path[count + 3] == 'v')
					{
						if (exe_path[count + 4] == 'o')
						{
							if (exe_path[count + 5] == 'i')
							{
								if (exe_path[count + 6] == 'c')
								{
									if (exe_path[count + 7] == 'e')
									{
										if (exe_path[count + 8] == '.')
										{
											if (exe_path[count + 9] == 'e')
											{
												if (exe_path[count + 10] == 'x')
												{
													if (exe_path[count + 11] == 'e')
													{
														break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	path_path = new char[directorysize + 10 + 1];
	char pathfilename[12] = "Config/path";

	for (int count(0); count < directorysize - 1; ++count)
	{
		path_path[count] = exe_path[count];
	}
	for (int count(0); count < 11; ++count)
	{
		path_path[directorysize - 1 + count] = pathfilename[count];
	}
	path_path[directorysize + 10] = '\0';

	std::string pathfinalpath = sconvert(path_path, (directorysize + 10 + 1));
	delete[] path_path;
	path_path = nullptr;
	return pathfinalpath;
}

std::string loadpathinifile()
{
	// load config
	char exe_path[MAX_PATH];
	char* pathini_path = nullptr;
	HMODULE hmodule = GetModuleHandle(NULL);
	GetModuleFileNameA(hmodule, exe_path, (sizeof(exe_path)));
	int directorysize(0);

	for (int count(0); count < 260; ++count)
	{
		++directorysize;
		// find LoLvoice.exe
		if (exe_path[count] == 'L')
		{
			if (exe_path[count + 1] == 'o')
			{
				if (exe_path[count + 2] == 'L')
				{
					if (exe_path[count + 3] == 'v')
					{
						if (exe_path[count + 4] == 'o')
						{
							if (exe_path[count + 5] == 'i')
							{
								if (exe_path[count + 6] == 'c')
								{
									if (exe_path[count + 7] == 'e')
									{
										if (exe_path[count + 8] == '.')
										{
											if (exe_path[count + 9] == 'e')
											{
												if (exe_path[count + 10] == 'x')
												{
													if (exe_path[count + 11] == 'e')
													{
														break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	pathini_path = new char[directorysize + 13 + 1];
	char pathinifilename[15] = "Config/pathini";

	for (int count(0); count < directorysize - 1; ++count)
	{
		pathini_path[count] = exe_path[count];
	}
	for (int count(0); count < 14; ++count)
	{
		pathini_path[directorysize - 1 + count] = pathinifilename[count];
	}
	pathini_path[directorysize + 13] = '\0';

	std::string pathinifinalpath = sconvert(pathini_path, (directorysize + 13 + 1));
	delete[] pathini_path;
	pathini_path = nullptr;
	return pathinifinalpath;
}

std::string loadpathtempfile()
{
	// load config
	char exe_path[MAX_PATH];
	char* pathtemp_path = nullptr;
	HMODULE hmodule = GetModuleHandle(NULL);
	GetModuleFileNameA(hmodule, exe_path, (sizeof(exe_path)));
	int directorysize(0);

	for (int count(0); count < 260; ++count)
	{
		++directorysize;
		// find LoLvoice.exe
		if (exe_path[count] == 'L')
		{
			if (exe_path[count + 1] == 'o')
			{
				if (exe_path[count + 2] == 'L')
				{
					if (exe_path[count + 3] == 'v')
					{
						if (exe_path[count + 4] == 'o')
						{
							if (exe_path[count + 5] == 'i')
							{
								if (exe_path[count + 6] == 'c')
								{
									if (exe_path[count + 7] == 'e')
									{
										if (exe_path[count + 8] == '.')
										{
											if (exe_path[count + 9] == 'e')
											{
												if (exe_path[count + 10] == 'x')
												{
													if (exe_path[count + 11] == 'e')
													{
														break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	pathtemp_path = new char[directorysize + 15 + 1];
	char pathtempfilename[17] = "Config/path_temp";

	for (int count(0); count < directorysize - 1; ++count)
	{
		pathtemp_path[count] = exe_path[count];
	}
	for (int count(0); count < 16; ++count)
	{
		pathtemp_path[directorysize - 1 + count] = pathtempfilename[count];
	}
	pathtemp_path[directorysize + 15] = '\0';

	std::string pathtempfinalpath = sconvert(pathtemp_path, (directorysize + 15 + 1));
	delete[] pathtemp_path;
	pathtemp_path = nullptr;
	return pathtempfinalpath;
}

std::string loaduserpassfile()
{
	// load exe
	char exe_path[MAX_PATH];
	char* userpass_path = nullptr;
	HMODULE hmodule = GetModuleHandle(NULL);
	GetModuleFileNameA(hmodule, exe_path, (sizeof(exe_path)));
	int directorysize(0);

	for (int count(0); count < 260; ++count)
	{
		++directorysize;
		// find LoLvoice.exe
		if (exe_path[count] == 'L')
		{
			if (exe_path[count + 1] == 'o')
			{
				if (exe_path[count + 2] == 'L')
				{
					if (exe_path[count + 3] == 'v')
					{
						if (exe_path[count + 4] == 'o')
						{
							if (exe_path[count + 5] == 'i')
							{
								if (exe_path[count + 6] == 'c')
								{
									if (exe_path[count + 7] == 'e')
									{
										if (exe_path[count + 8] == '.')
										{
											if (exe_path[count + 9] == 'e')
											{
												if (exe_path[count + 10] == 'x')
												{
													if (exe_path[count + 11] == 'e')
													{
														break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	userpass_path = new char[directorysize + 14 + 1];
	char userpassfilename[16] = "Config/userpass";

	for (int count(0); count < directorysize - 1; ++count)
	{
		userpass_path[count] = exe_path[count];
	}
	for (int count(0); count < 15; ++count)
	{
		userpass_path[directorysize - 1 + count] = userpassfilename[count];
	}
	userpass_path[directorysize + 14] = '\0';

	std::string userpassfinalpath = sconvert(userpass_path, (directorysize + 14 + 1));
	delete[] userpass_path;
	userpass_path = nullptr;
	return userpassfinalpath;
}

std::string loaduserpasstempfile()
{
	// load exe
	char exe_path[MAX_PATH];
	char* userpasstemp_path = nullptr;
	HMODULE hmodule = GetModuleHandle(NULL);
	GetModuleFileNameA(hmodule, exe_path, (sizeof(exe_path)));
	int directorysize(0);

	for (int count(0); count < 260; ++count)
	{
		++directorysize;
		// find LoLvoice.exe
		if (exe_path[count] == 'L')
		{
			if (exe_path[count + 1] == 'o')
			{
				if (exe_path[count + 2] == 'L')
				{
					if (exe_path[count + 3] == 'v')
					{
						if (exe_path[count + 4] == 'o')
						{
							if (exe_path[count + 5] == 'i')
							{
								if (exe_path[count + 6] == 'c')
								{
									if (exe_path[count + 7] == 'e')
									{
										if (exe_path[count + 8] == '.')
										{
											if (exe_path[count + 9] == 'e')
											{
												if (exe_path[count + 10] == 'x')
												{
													if (exe_path[count + 11] == 'e')
													{
														break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	userpasstemp_path = new char[directorysize + 19 + 1];
	char userpasstempfilename[21] = "Config/userpass_temp";

	for (int count(0); count < directorysize - 1; ++count)
	{
		userpasstemp_path[count] = exe_path[count];
	}
	for (int count(0); count < 20; ++count)
	{
		userpasstemp_path[directorysize - 1 + count] = userpasstempfilename[count];
	}
	userpasstemp_path[directorysize + 19] = '\0';

	std::string userpasstempfinalpath = sconvert(userpasstemp_path, (directorysize + 19 + 1));
	delete[] userpasstemp_path;
	userpasstemp_path = nullptr;
	return userpasstempfinalpath;
}

void createPathtoExeDirectory(char* &defaultpath, int &length)
{
	// load path
	char exe_path[MAX_PATH];
	HMODULE hmodule = GetModuleHandle(NULL);
	GetModuleFileNameA(hmodule, exe_path, (sizeof(exe_path)));
	int directorysize(0);
	for (int count(0); count < 260; ++count)
	{
		++directorysize;
		// find LoLvoice.exe
		if (exe_path[count] == 'L')
		{
			if (exe_path[count + 1] == 'o')
			{
				if (exe_path[count + 2] == 'L')
				{
					if (exe_path[count + 3] == 'v')
					{
						if (exe_path[count + 4] == 'o')
						{
							if (exe_path[count + 5] == 'i')
							{
								if (exe_path[count + 6] == 'c')
								{
									if (exe_path[count + 7] == 'e')
									{
										if (exe_path[count + 8] == '.')
										{
											if (exe_path[count + 9] == 'e')
											{
												if (exe_path[count + 10] == 'x')
												{
													if (exe_path[count + 11] == 'e')
													{
														break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	defaultpath = new char[directorysize - 1];
	for (int count(0); count < directorysize - 2; ++count)
	{
		defaultpath[count] = exe_path[count];
	}
	defaultpath[directorysize - 2] = '\0';
	length = directorysize - 1;
}

bool checkiffoldersexist(std::string folder)
{
	// LoLvoice.exe config folder path
	char* folderPath = nullptr;
	char foldername[8] = "/Config";
	folderPath = new char[folder.length() / sizeof(folder[0]) + 7 + 1];

	for (int count(0); count < folder.length()/sizeof(folder[0]); ++count)
	{
		folderPath[count] = folder[count];
	}
	for (int count(0); count < 7; ++count)
	{
		folderPath[folder.length() / sizeof(folder[0]) + count] = foldername[count];
	}
	folderPath[folder.length() / sizeof(folder[0]) + 7] = '\0';

	std::string folderconfig = sconvert(folderPath, (folder.length() / sizeof(folder[0]) + 7));

	delete[] folderPath;
	folderPath = nullptr;
	struct stat buffer;

	if (stat(folderconfig.c_str(), &buffer) == 0)
	{
	}
	if ((stat(folderconfig.c_str(), &buffer) == 0) == false)
	{
		return (stat(folderconfig.c_str(), &buffer) == 0);
	}

	// LoLvoice.exe en-us folder path
	char* enusfolder = nullptr;
	char enusname[7] = "/en-us";
	enusfolder = new char[folder.length() / sizeof(folder[0]) + 6 + 1];

	for (int count(0); count < folder.length() / sizeof(folder[0]); ++count)
	{
		enusfolder[count] = folder[count];
	}
	for (int count(0); count < 6; ++count)
	{
		enusfolder[folder.length() / sizeof(folder[0]) + count] = enusname[count];
	}
	enusfolder[folder.length() / sizeof(folder[0]) + 6] = '\0';

	std::string folderenus = sconvert(enusfolder, (folder.length() / sizeof(folder[0]) + 6));

	delete[] enusfolder;
	enusfolder = nullptr;
	struct stat buffer_enus;

	if (stat(folderenus.c_str(), &buffer_enus) == 0)
	{
	}
	if ((stat(folderenus.c_str(), &buffer) == 0) == false)
	{
		return (stat(folderenus.c_str(), &buffer_enus) == 0);
	}
}
