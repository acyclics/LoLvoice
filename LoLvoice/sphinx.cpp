#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>
#include <thread>
#include <vector>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

std::string recognize_from_microphone();
void alpaOut(char char_array[], int length);
void alpaOut_string(std::string speech);
bool psChecker();
bool micState = false;
bool micClose = false;

ps_decoder_t *ps;                  // create pocketsphinx decoder structure
cmd_ln_t *config;                  // create configuration structure
ad_rec_t *ad;                      // create audio recording structure - for use with ALSA functions

int viewKey();
void initializePaths();
bool checkifmllrexist();
std::string sconvert(const char *pCh, int arraySize);
std::string loadconfigfile();
void dividearrays_sphinx(char array1[], char** &array2, int sizeofarray1, int &numberofphrase, int* &dividedarraysize);
std::string loadsphinxoutputfile();

// char arrays for loading file paths
char * array_file = nullptr;
char * array_file_hmm = nullptr;
char * array_file_lm = nullptr;
char * array_file_dict = nullptr;
char * mllr_file = nullptr;
char array_hmm[13] = "/en-us/en-us";
char array_lm[20] = "/en-us/en-us.lm.bin";
char array_dict[26] = "/en-us/cmudict-en-us.dict";
char mllr_path[27] = "/adapt/records/mllr_matrix";
int sizee(0);
std::string line;
int keybind(0);

void inputFile()
{
	// load path from config
	std::string configfinalpath = loadconfigfile();
	std::ifstream myfile(configfinalpath);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			sizee = (line.length() / sizeof(line[0]))-1;
			array_file = new char[sizee-25];
			for (int count(0); count < (sizee-25); ++count)
			{
				array_file[count] = line[count+25];
			}
		}
		myfile.close();
	}

	// for hmm
	array_file_hmm = new char[sizee-25 + 13];						
	for (int count(0); count < sizee-25; ++count)
	{
		array_file_hmm[count] = array_file[count];
	}
	for (int count(0); count < 13; ++count)
	{
		array_file_hmm[(sizee-25) + count] = array_hmm[count];
	}
	
	// for lm
	array_file_lm = new char[sizee - 25 + 20];
	for (int count(0); count < sizee - 25; ++count)
	{
		array_file_lm[count] = array_file[count];
	}
	for (int count(0); count < 20; ++count)
	{
		array_file_lm[(sizee - 25) + count] = array_lm[count];
	}

	// for dict
	array_file_dict = new char[sizee - 25 + 26];
	for (int count(0); count < sizee - 25; ++count)
	{
		array_file_dict[count] = array_file[count];
	}
	for (int count(0); count < 26; ++count)
	{
		array_file_dict[(sizee - 25) + count] = array_dict[count];
	}

	// for mllr_matrix
	if (checkifmllrexist())
	{
		mllr_file = new char[sizee - 25 + 27];
		for (int count(0); count < sizee - 25; ++count)
		{
			mllr_file[count] = array_file[count];
		}
		for (int count(0); count < 27; ++count)
		{
			mllr_file[(sizee - 25) + count] = mllr_path[count];
		}
	}

}

inline void pressEnter(INPUT ip2)
{
	ip2.ki.wVk = VK_RETURN;
	ip2.ki.dwFlags = 0;
	SendInput(1, &ip2, sizeof(INPUT));
	ip2.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip2, sizeof(INPUT));
}

void defineconfig()
{
	if (checkifmllrexist())
	{
		// if created mllr
		config = cmd_ln_init(NULL, ps_args(), TRUE,                   // Load the configuration structure - ps_args() passes the default values
			"-hmm", array_file_hmm,									    // path to the standard english language model
			"-lm", array_file_lm,                                         // custom language model (file must be present)
			"-dict", array_file_dict,	  // custom dictionary (file must be present)  
			"-mllr", mllr_file,		// adapted model
			NULL);
	}
	else
	{
		config = cmd_ln_init(NULL, ps_args(), TRUE,                   // Load the configuration structure - ps_args() passes the default values
			"-hmm", array_file_hmm,									    // path to the standard english language model
			"-lm", array_file_lm,                                         // custom language model (file must be present)
			"-dict", array_file_dict,	  // custom dictionary (file must be present)  
			NULL);
	}

	ps = ps_init(config);                                                        // initialize the pocketsphinx decoder
	ad = ad_open_dev("sysdefault", (int)cmd_ln_float32_r(config, "-samprate")); // open default microphone at default samplerate
}

void startRecord()
{
	inputFile();		// load files from user defined path

	defineconfig();		// load pocketsphinx decoder configs

	// cleanup
	delete[] array_file;
	array_file = nullptr;

	delete[] array_file_hmm;
	array_file_hmm = nullptr;

	delete[] array_file_lm;
	array_file_lm = nullptr;

	delete[] array_file_dict;
	array_file_dict = nullptr;

	delete[] mllr_file;
	mllr_file = nullptr;

	keybind = viewKey();		// load keybind from config file

	int sphinxoutputmode_int(0);
	std::string sphinxoutputmode = loadsphinxoutputfile();
	std::ifstream pathfile(sphinxoutputmode);
	pathfile >> sphinxoutputmode_int;
	pathfile.close();

	// string decoded_speech;
	INPUT ip2;
	ip2.type = INPUT_KEYBOARD;
	ip2.ki.wScan = 0;
	ip2.ki.time = 0;
	ip2.ki.dwExtraInfo = 0;
	bool switcher = true;

	if (sphinxoutputmode_int == 0)
	{
		while (switcher)
		{
			Sleep(1);									// cheap way of lowering cpu usage. should be fine though since user must hold keybind to input
			if (micState == true) {
				while ((GetKeyState(keybind) & 0x80) != 0)
				{					// when user press the keybind start input
					std::string decoded_speech = recognize_from_microphone();          // call the function to capture and decode speech
					pressEnter(ip2);
					alpaOut_string(decoded_speech);
					Sleep(60);													// must edit this and adjust for in-game
					pressEnter(ip2);
				}
			}
			if (micClose == true)
			{
				ad_close(ad);

				delete[] array_file;
				array_file = nullptr;

				delete[] array_file_hmm;
				array_file_hmm = nullptr;

				delete[] array_file_lm;
				array_file_lm = nullptr;

				delete[] array_file_dict;
				array_file_dict = nullptr;

				delete[] mllr_file;
				mllr_file = nullptr;

				switcher = false;
			}
		}
	}
	if (sphinxoutputmode_int == 1)
	{
		while (switcher)
		{
			Sleep(1);									// cheap way of lowering cpu usage. should be fine though since user must hold keybind to input
			if (micState == true) {
				while ((GetKeyState(keybind) & 0x80) != 0)
				{					// when user press the keybind start input
					std::string decoded_speech = recognize_from_microphone();          // call the function to capture and decode speech           
					char char_array[1000];
					strcpy_s(char_array, decoded_speech.c_str());
					int countofarray(0), totalcountofarray(0);
					int * dividedarraysizeofbuffer = nullptr;
					char ** dividedarray = nullptr;
					dividearrays_sphinx(char_array, dividedarray, decoded_speech.length() / sizeof(decoded_speech[0]), totalcountofarray, dividedarraysizeofbuffer);
					while (countofarray != totalcountofarray)
					{
						pressEnter(ip2);
						alpaOut(dividedarray[countofarray], dividedarraysizeofbuffer[countofarray]);
						Sleep(60);
						pressEnter(ip2);
						++countofarray;
					}
					if (decoded_speech.length() / sizeof(decoded_speech[0]) != 0)
					{
						// might have to add this to above too
						delete[] dividedarraysizeofbuffer;
						delete[] dividedarray;
					}
					dividedarraysizeofbuffer = nullptr;
					dividedarray = nullptr;
				}
			}
			if (micClose == true)
			{
				ad_close(ad);

				delete[] array_file;
				array_file = nullptr;

				delete[] array_file_hmm;
				array_file_hmm = nullptr;

				delete[] array_file_lm;
				array_file_lm = nullptr;

				delete[] array_file_dict;
				array_file_dict = nullptr;

				delete[] mllr_file;
				mllr_file = nullptr;

				switcher = false;
			}
		}
	}
}

std::string recognize_from_microphone() 
{
	int16 adbuf[1000];                 // buffer array to hold audio data
	uint8 utt_started, in_speech;      // flags for tracking active speech - has speech started? - is speech currently happening?
	int32 k;                           // holds the number of frames in the audio buffer
	char const *hyp;                   // pointer to "hypothesis" (best guess at the decoded result)

	ad_start_rec(ad);                                // start recording
	ps_start_utt(ps);                                // mark the start of the utterance
	utt_started = FALSE;                             // clear the utt_started flag

	while (1) 
	{
		k = ad_read(ad, adbuf, 1000);                // capture the number of frames in the audio buffer
		ps_process_raw(ps, adbuf, k, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder

		in_speech = ps_get_in_speech(ps);            // test to see if speech is being detected

		if (in_speech && !utt_started) {             // if speech has started and utt_started flag is false                            
			utt_started = TRUE;                      // then set the flag
		}

		/*
		if (!in_speech && utt_started) {             // if speech has ended and the utt_started flag is true 
			ps_end_utt(ps);                          // then mark the end of the utterance
			ad_stop_rec(ad);                         // stop recording
			hyp = ps_get_hyp(ps, NULL);             // query pocketsphinx for "hypothesis" of decoded statement
			return hyp;                              // the function returns the hypothesis
			break;                                   // exit the while loop and return to main
		}
	*/

		if (!((GetKeyState(keybind) & 0x80) != 0) && utt_started) {             // if keybind is released and the utt_started flag is true 
			!in_speech;
			ps_end_utt(ps);                          // then mark the end of the utterance
			ad_stop_rec(ad);                         // stop recording
			hyp = ps_get_hyp(ps, NULL);             // query pocketsphinx for "hypothesis" of decoded statement
			return hyp;                              // the function returns the hypothesis
			break;                                   // exit the while loop and return to main
		}
		
	}

}

void dividearrays_sphinx(char array1[], char** &array2, int sizeofarray1, int &numberofphrase, int* &dividedarraysize)
{
	int numberofspace(0);
	for (int count(0); count < sizeofarray1; ++count)
	{
		if (array1[count] == ' ')
		{
			++numberofspace;
		}
	}

	if (numberofspace > 3)
	{
		// need to divide
		double roundnoofwords = static_cast<double>(numberofspace) / 3.0;
		if (roundnoofwords > numberofspace / 3)
		{
			numberofphrase = (numberofspace / 3) + 1;
		}
		else
		{
			numberofphrase = (numberofspace / 3);
		}
		array2 = new char*[numberofphrase];
		dividedarraysize = new int[numberofphrase];
		int countingwords(0), previouswords(0);
		int recordofpreviouswords(0);

		for (int phrases(0); phrases < numberofphrase; ++phrases)
		{
			recordofpreviouswords = previouswords;
			int countingspaces(0);
			countingwords = previouswords;

			for (countingwords; countingwords < sizeofarray1; ++countingwords)
			{
				if (array1[countingwords] == ' ')
				{
					++countingspaces;
				}
				++previouswords;
				if (countingspaces == 3)
					break;
			}

			if (countingspaces == 3)
			{
				array2[phrases] = new char[previouswords - 1 - recordofpreviouswords + 1];
				dividedarraysize[phrases] = previouswords - 1 - recordofpreviouswords;
				for (int count(0); count < previouswords - 1 - recordofpreviouswords; ++count)
				{
					array2[phrases][count] = array1[recordofpreviouswords + count];
				}
				array2[phrases][previouswords - 1 - recordofpreviouswords] = '\0';
			}
			else
			{
				array2[phrases] = new char[previouswords - recordofpreviouswords + 1];
				dividedarraysize[phrases] = previouswords - recordofpreviouswords;
				for (int count(0); count < previouswords - recordofpreviouswords; ++count)
				{
					array2[phrases][count] = array1[recordofpreviouswords + count];
				}
				array2[phrases][previouswords - recordofpreviouswords] = '\0';
			}
		}
	}
	else
	{
		// no need to divide
		numberofphrase = 1;
		array2 = new char*[numberofphrase];
		array2[0] = new char[sizeofarray1 + 1];
		dividedarraysize = new int[1];
		dividedarraysize[0] = sizeofarray1;
		for (int count(0); count < sizeofarray1; ++count)
		{
			array2[0][count] = array1[count];
		}
		array2[0][sizeofarray1] = '\0';
	}
}


void openMic()
{
	micState = true;		// set bool for when user pressed "Start". true = pressed start
}

void closeMic()
{
	micState = false;		// affect checkers that checks if mic is in use. false = in use
}

void miclose()
{
	micClose = true;			// affect checkers that checks if mic is in use. true = not in use
}

bool psChecker()
{
	if (ps == nullptr)				// check if pocketsphinx files are found. returns TRUE if NOT FOUND
	{
		return true;
	}
	return false;
}

char* returnPath()
{
	return array_file;			// return the lolvoice.exe directory path to caller
}

int returnSizee()
{
	return (sizee - 25);		// pass the size of lolvoice.exe directory path to caller 
}

std::string loadconfigfile()
{
	// load config
	char exe_path[MAX_PATH];
	char* config_path = nullptr;
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

	config_path = new char[directorysize + 12 + 1];
	char configfilename[14] = "Config/config";

	for (int count(0); count < directorysize - 1; ++count)
	{
		config_path[count] = exe_path[count];
	}
	for (int count(0); count < 13; ++count)
	{
		config_path[directorysize - 1 + count] = configfilename[count];
	}
	config_path[directorysize + 12] = '\0';

	std::string configfinalpath = sconvert(config_path, (directorysize + 12 + 1));
	delete[] config_path;
	config_path = nullptr;
	return configfinalpath;
}

std::string loadconfiginifile()
{
	// load config
	char exe_path[MAX_PATH];
	char* configini_path = nullptr;
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

	configini_path = new char[directorysize + 16 + 1];
	char configinifilename[18] = "Config/config_ini";

	for (int count(0); count < directorysize - 1; ++count)
	{
		configini_path[count] = exe_path[count];
	}
	for (int count(0); count < 17; ++count)
	{
		configini_path[directorysize - 1 + count] = configinifilename[count];
	}
	configini_path[directorysize + 16] = '\0';

	std::string configinifinalpath = sconvert(configini_path, (directorysize + 16 + 1));
	delete[] configini_path;
	configini_path = nullptr;
	return configinifinalpath;
}

std::string loadconfigtempfile()
{
	// load config
	char exe_path[MAX_PATH];
	char* configtemp_path = nullptr;
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

	configtemp_path = new char[directorysize + 17 + 1];
	char configtempfilename[19] = "Config/config_temp";

	for (int count(0); count < directorysize - 1; ++count)
	{
		configtemp_path[count] = exe_path[count];
	}
	for (int count(0); count < 18; ++count)
	{
		configtemp_path[directorysize - 1 + count] = configtempfilename[count];
	}
	configtemp_path[directorysize + 17] = '\0';

	std::string configtempfinalpath = sconvert(configtemp_path, (directorysize + 17 + 1));
	delete[] configtemp_path;
	configtemp_path = nullptr;
	return configtempfinalpath;
}

void changeKeybind()
{
	keybind = viewKey();
}

bool checkifsphinxfilesnotloaded()
{
	if (psChecker())
		return true;
	else
		return false;
}

std::string loadsphinxoutputfile()
{
	// load exe
	char exe_path[MAX_PATH];
	char* sphinx_outputmode = nullptr;
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

	sphinx_outputmode = new char[directorysize + 23 + 1];
	char sphinxoutputmodefilename[25] = "Config/sphinx_outputmode";

	for (int count(0); count < directorysize - 1; ++count)
	{
		sphinx_outputmode[count] = exe_path[count];
	}
	for (int count(0); count < 24; ++count)
	{
		sphinx_outputmode[directorysize - 1 + count] = sphinxoutputmodefilename[count];
	}
	sphinx_outputmode[directorysize + 23] = '\0';

	std::string sphinxoutputfinalpath = sconvert(sphinx_outputmode, (directorysize + 23 + 1));
	delete[] sphinx_outputmode;
	sphinx_outputmode = nullptr;
	return sphinxoutputfinalpath;
}

std::string loadsphinxoutputtempfile()
{
	// load exe
	char exe_path[MAX_PATH];
	char* sphinx_outputmode = nullptr;
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

	sphinx_outputmode = new char[directorysize + 28 + 1];
	char sphinxoutputmodefilename[30] = "Config/sphinx_outputmode_temp";

	for (int count(0); count < directorysize - 1; ++count)
	{
		sphinx_outputmode[count] = exe_path[count];
	}
	for (int count(0); count < 29; ++count)
	{
		sphinx_outputmode[directorysize - 1 + count] = sphinxoutputmodefilename[count];
	}
	sphinx_outputmode[directorysize + 28] = '\0';

	std::string sphinxoutputfinalpath = sconvert(sphinx_outputmode, (directorysize + 28 + 1));
	delete[] sphinx_outputmode;
	sphinx_outputmode = nullptr;
	return sphinxoutputfinalpath;
}