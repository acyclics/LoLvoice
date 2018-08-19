#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

char* returnPath();
int returnSizee();
void createMFC(char* mfcexe, char* mfcpath);
void useBW(char* bwexe, char* bwpath);
void mllrTransform(char* mllrexe, char* mllrpath);
void mapAdapt(char* mapexe, char* mappath);
void senDump(char* senDumpexe, char* senDumppath);
std::string loadconfigfile();
bool mfc_status = false;
bool bw_status = false;
bool mllr_status = false;
bool map_status = false;
void inputFile();

// create exe path by appending to char array
void getPaths(char* (&finalpath), const char* path, const int pathlen, const char* append, int appendlen)
{
	finalpath = new char[pathlen + appendlen];
	for (int count(0); count < pathlen; ++count)
	{
		finalpath[count] = path[count];
	}
	for (int count(0); count < appendlen; ++count)
	{
		finalpath[pathlen + count] = append[count];
	}
}

// create command line arguments
void getPathsEX(char* (&finalpath), const char* prefix, const int prefixlen, const std::string appendarray[], const int appendarraysize)
{
	// processing appendarray
	int size(0);

	// add appendarraysize
	for (int count(0); count < appendarraysize; ++count)
	{
		size += appendarray[count].length();
	}
	finalpath = new char[size + prefixlen+1];

	// keep count of all added char
	int arraycount(0);

	// add prefix
	for (int count(0); count < prefixlen; ++count)
	{
		finalpath[arraycount] = prefix[count];
		++arraycount;
	}

	// append arguments
	for (int counting(0); counting < appendarraysize; ++counting)
	{
		for (int count(0); count < appendarray[counting].length(); ++count)
		{
			finalpath[arraycount] = appendarray[counting][count];
			++arraycount;
		}
	}

	// append null
	finalpath[arraycount] = '\0';
}

// char array to string
std::string sconvert(const char *pCh, int arraySize) {
	std::string str;
	if (pCh[arraySize - 1] == '\0') str.append(pCh);
	else for (int i = 0; i<arraySize; i++) str.append(1, pCh[i]);
	return str;
}

void initializePaths()
{
	// LoLvoice.exe path
	std::string finalconfigpath = loadconfigfile();
	char* folderPath = nullptr;
	std::string line;
	std::ifstream myfile(finalconfigpath);
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
	const int len = returnSizee();
	std::string folderPathstr = sconvert(folderPath, len);

	// for mfc.exe
	char* mfcexe = nullptr;
	const char sphinxfe_exe[21] = "/adapt/sphinx_fe.exe";
	getPaths(mfcexe, folderPath, len, sphinxfe_exe, 21);

	// for mfc.cmd
	char* mfcpath = nullptr;
	const char sphinxfe_word[14] = "sphinx_fe.exe";
	std::string mfcstr[] { " -argfile ", folderPathstr, "/en-us/en-us/feat.params", " -samprate 16000 -c ", folderPathstr, "/adapt/records/arctic20.fileids", " -di ", folderPathstr, "/adapt/records", " -do ", folderPathstr, "/adapt/records", " -ei wav -eo mfc -mswav yes"};
	getPathsEX(mfcpath, sphinxfe_word, 13, mfcstr, 13);

	// initiate mfc
	createMFC(mfcexe, mfcpath);
	delete[] mfcexe;
	mfcexe = nullptr;
	delete[] mfcpath;
	mfcpath = nullptr;

	// for bw.exe
	char* bwexe = nullptr;
	const char bw_exe[22] = "/adapt/records/bw.exe";
	getPaths(bwexe, folderPath, len, bw_exe, 22);

	// for bw.cmd
	char* bwpath = nullptr;
	const char bw_word[7] = "bw.exe";
	std::string bwstr[]{ " -hmmdir ", folderPathstr, "/en-us/en-us", " -moddeffn ", folderPathstr, "/en-us/en-us/mdef", " -ts2cbfn .ptm. -feat 1s_c_d_dd -svspec 0-12/13-25/26-38 -cmn current -agc none -dictfn ", folderPathstr, "/en-us/cmudict-en-us.dict", " -ctlfn ", folderPathstr, "/adapt/records/arctic20.fileids", " -lsnfn ", folderPathstr, "/adapt/records/arctic20.transcription", " -accumdir ", folderPathstr, "/adapt/records", " -cepdir ", folderPathstr, "/adapt/records" };
	getPathsEX(bwpath, bw_word, 6, bwstr, 21);

	// initiate bw
	useBW(bwexe, bwpath);
	delete[] bwexe;
	bwexe = nullptr;
	delete[] bwpath;
	bwpath = nullptr;

	// for mllr.exe
	char* mllrexe = nullptr;
	const char mllr_exe[22] = "/adapt/mllr_solve.exe";
	getPaths(mllrexe, folderPath, len, mllr_exe, 22);

	// for mllr.cmd
	char* mllrpath = nullptr;
	const char mllr_word[15] = "mllr_solve.exe";
	std::string mllrstr[]{ " -meanfn ", folderPathstr,"/en-us/en-us/means", " -varfn ", folderPathstr, "/en-us/en-us/variances", " -outmllrfn ", folderPathstr, "/adapt/records/mllr_matrix", " -accumdir ", folderPathstr, "/adapt/records" };
	getPathsEX(mllrpath, mllr_word, 14, mllrstr, 12);

	// initiate mllr
	mllrTransform(mllrexe, mllrpath);
	delete[] mllrexe;
	mllrexe = nullptr;
	delete[] mllrpath;
	mllrpath = nullptr;

	// for map.exe
	char* mapexe = nullptr;
	const char map_exe[29] = "/adapt/records/map_adapt.exe";
	getPaths(mapexe, folderPath, len, map_exe, 29);

	// for map.cmd
	char* mappath = nullptr;
	const char map_word[14] = "map_adapt.exe";
	std::string mapstr[]{ " -moddeffn ", folderPathstr, "/en-us/en-us/mdef", " -ts2cbfn .ptm. -meanfn ", folderPathstr, "/en-us/en-us/means", " -varfn ", folderPathstr, "/en-us/en-us/variances", " -mixwfn ", folderPathstr, "/en-us/en-us/mixture_weights", " -tmatfn ", folderPathstr, "/en-us/en-us/transition_matrices", " -accumdir ", folderPathstr, "/adapt/records", " -mapmeanfn ", folderPathstr, "/en-us-adapt/en-us/means", " -mapvarfn ", folderPathstr, "/en-us-adapt/en-us/variances", " -mapmixwfn ", folderPathstr, "/en-us-adapt/en-us/mixture_weights", " -maptmatfn ", folderPathstr, "/en-us-adapt/en-us/transition_matrices" };
	getPathsEX(mappath, map_word, 13, mapstr, 30);

	// initiate map
	mapAdapt(mapexe, mappath);
	delete[] mappath;
	mappath = nullptr;

	// for map.exe initial folder
	char* mappath_initial = nullptr;
	std::string mapstr_initial[]{ " -moddeffn ", folderPathstr, "/en-us/en-us/mdef", " -ts2cbfn .ptm. -meanfn ", folderPathstr, "/en-us/en-us/means", " -varfn ", folderPathstr, "/en-us/en-us/variances", " -mixwfn ", folderPathstr, "/en-us/en-us/mixture_weights", " -tmatfn ", folderPathstr, "/en-us/en-us/transition_matrices", " -accumdir ", folderPathstr, "/adapt/records", " -mapmeanfn ", folderPathstr, "/en-us-adapt/means", " -mapvarfn ", folderPathstr, "/en-us-adapt/variances", " -mapmixwfn ", folderPathstr, "/en-us-adapt/mixture_weights", " -maptmatfn ", folderPathstr, "/en-us-adapt/transition_matrices" };
	getPathsEX(mappath, map_word, 13, mapstr, 30);

	// initiate map initial
	mapAdapt(mapexe, mappath_initial);
	delete[] mapexe;
	mapexe = nullptr;
	delete[] mappath_initial;
	mappath_initial = nullptr;

	// for senDump.exe
	char* senDumpexe = nullptr;
	const char senDump_exe[32] = "/adapt/records/mk_s2sendump.exe";
	getPaths(senDumpexe, folderPath, len, senDump_exe, 32);

	// for senDump.cmd
	char* senDumppath = nullptr;
	const char senDump_word[17] = "mk_s2sendump.exe";
	std::string senDumpstr[]{ " -pocketsphinx yes -moddeffn ", folderPathstr, "/en-us-adapt/en-us/mdef", " -mixwfn ", folderPathstr, "/en-us-adapt/en-us/mixture_weights", " -sendumpfn ", folderPathstr, "/en-us-adapt/en-us/sendump" };
	getPathsEX(senDumppath, senDump_word, 16, senDumpstr, 9);

	// initiate senDump
	senDump(senDumpexe, senDumppath);
	delete[] senDumpexe;
	senDumpexe = nullptr;
	delete[] senDumppath;
	senDumppath = nullptr;

	// cleanup
	delete[] folderPath;
	folderPath = nullptr;
}

// functions for adapting sphinx model
void createMFC(char* mfcexe, char* mfcpath)
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (CreateProcessA(
		mfcexe,   // the path
		mfcpath,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		CREATE_NO_WINDOW,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	))
	{
		WaitForSingleObject(pi.hProcess, 30*1000);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		mfc_status = true;
		MessageBoxA(NULL, "Error initiating sphinx_fe.exe.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
	}
}

void useBW(char* bwexe, char* bwpath)
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (CreateProcessA(
		bwexe,   // the path
		bwpath,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		CREATE_NO_WINDOW,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	))
	{
		WaitForSingleObject(pi.hProcess, 30 * 1000);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		if (mfc_status == true)
		{
		}
		else
		{
			bw_status = true;
			MessageBoxA(NULL, "Error initiating bw.exe.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
		}
	}
}

void mllrTransform(char* mllrexe, char* mllrpath)
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (CreateProcessA(
		mllrexe,   // the path
		mllrpath,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		CREATE_NO_WINDOW,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	))
	{
		WaitForSingleObject(pi.hProcess, 30 * 1000);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		if (mfc_status == true || bw_status == true)
		{
		}
		else
		{
			mllr_status = true;
			MessageBoxA(NULL, "Error initiating mllr_transform.exe.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
		}
	}
}

void mapAdapt(char* mapexe, char* mappath)
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (CreateProcessA(
		mapexe,   // the path
		mappath,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		CREATE_NO_WINDOW,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	))
	{
		WaitForSingleObject(pi.hProcess, 30 * 1000);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		if (mfc_status == true || bw_status == true || mllr_status == true)
		{
		}
		else
		{
			map_status = true;
			MessageBoxA(NULL, "Error initiating map_adapt.exe.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
		}
	}
}

void senDump(char* senDumpexe, char* senDumppath)
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (CreateProcessA(
		senDumpexe,   // the path
		senDumppath,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		CREATE_NO_WINDOW,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
	))
	{
		WaitForSingleObject(pi.hProcess, 30 * 1000);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		if (mfc_status == true || bw_status == true || mllr_status == true || map_status == true)
		{
		}
		else
		{
			MessageBoxA(NULL, "Error initiating mk_s2sendump.exe.", "ERROR", MB_ICONWARNING | MB_DEFBUTTON2);
		}
	}
}

// returns true if directory contains mllr_matrix
bool checkifmllrexist() 
{
	// LoLvoice.exe path
	std::string finalconfigpath = loadconfigfile();
	char* folderPath = nullptr;
	std::string line;
	std::ifstream myfile(finalconfigpath);
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
	const int len = returnSizee();
	std::string folderPathstr = sconvert(folderPath, len);
	char pathtomllr[27] = "/adapt/records/mllr_matrix";

	std::string* mllr_file = new std::string[len + 27];
	for (int count(0); count < len; ++count)
	{
		mllr_file[count] = folderPathstr[count];
	}
	for (int count(0); count < 27; ++count)
	{
		mllr_file[len + count] = pathtomllr[count];
	}

	std::string name;

	for (int count(0); count < (len + 27); ++count)
	{
		name.append(mllr_file[count]);
	}

	delete[] folderPath;
	folderPath = nullptr;
	delete[] mllr_file;
	mllr_file = nullptr;
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
