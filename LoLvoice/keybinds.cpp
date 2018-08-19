#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <istream>

std::string sconvert(const char *pCh, int arraySize);
std::string loadkeybindfile();
std::string loadkeybindinifile();
std::string loadkeybindtempfile();
std::string loadoverdrivefile();
std::string loadoverdriveinifile();
std::string loadoverdrivetempfile();

// numb is in file scope as detectKeyPress will be looped, avoids redefining
int numb(0);
int numb_overdrive(0);
int numb_cancel(0);
int numb_allchat(0);

// detectKeyPress detects user pressed key and stores it in file
void detectKeyPress()
{
	bool lock = true;
	while (lock)
	{
		// backspace key

		if ((GetKeyState(VK_BACK) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x08;
			
		}
		// tab key
		if ((GetKeyState(VK_TAB) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x09;
			
		}
		// return key
		if ((GetKeyState(VK_RETURN) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x0D;
			
		}
		// shift key
		if ((GetKeyState(VK_SHIFT) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x10;
			
		}
		// control key
		if ((GetKeyState(VK_CONTROL) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x11;
			
		}
		// alt key
		if ((GetKeyState(VK_MENU) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x12;
			
		}
		// pause key
		if ((GetKeyState(VK_PAUSE) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x13;
			
		}
		// caps-lock key
		if ((GetKeyState(VK_CAPITAL) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x14;
			
		}
		// esc key
		if ((GetKeyState(VK_ESCAPE) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x1B;
			
		}
		// caps-lock key
		if ((GetKeyState(VK_SPACE) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x20;
			
		}
		// page-up key
		if ((GetKeyState(VK_PRIOR) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x21;
			
		}
		// page-down key
		if ((GetKeyState(VK_NEXT) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x22;
			
		}
		// end key
		if ((GetKeyState(VK_END) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x23;
			
		}
		// home key
		if ((GetKeyState(VK_HOME) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x24;
			
		}
		// left-arrow key
		if ((GetKeyState(VK_LEFT) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x25;
			
		}
		// up-arrow key
		if ((GetKeyState(VK_UP) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x26;
			
		}
		// right-arrow key
		if ((GetKeyState(VK_RIGHT) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x27;
			
		}
		// down-arrow key
		if ((GetKeyState(VK_DOWN) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x28;
			
		}
		// select key
		if ((GetKeyState(VK_SELECT) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x29;
			
		}
		// print key
		if ((GetKeyState(VK_PRINT) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x2A;
			
		}
		// execute key
		if ((GetKeyState(VK_EXECUTE) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x2B;
			
		}
		// pr-screen key
		if ((GetKeyState(VK_SNAPSHOT) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x2C;
			
		}
		// insert key
		if ((GetKeyState(VK_INSERT) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x2D;
			
		}
		// delete key
		if ((GetKeyState(VK_DELETE) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x2E;
			
		}
		// 0 key
		if ((GetKeyState(0x30) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x30;
			
		}
		// 1 key
		if ((GetKeyState(0x31) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x31;
			
		}
		// 2 key
		if ((GetKeyState(0x32) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x32;
			
		}
		// 3 key
		if ((GetKeyState(0x33) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x33;
			
		}
		// 4 key
		if ((GetKeyState(0x34) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x34;
			
		}
		// 5 key
		if ((GetKeyState(0x35) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x35;
			
		}
		// 6 key
		if ((GetKeyState(0x36) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x36;
			
		}
		// 7 key
		if ((GetKeyState(0x37) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x37;
			
		}
		// 8 key
		if ((GetKeyState(0x38) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x38;
			
		}
		// 9 key
		if ((GetKeyState(0x39) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x39;
			
		}
		// A key
		if ((GetKeyState(0x41) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x41;
			
		}
		// B key
		if ((GetKeyState(0x42) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x42;
			
		}
		// C key
		if ((GetKeyState(0x43) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x43;
			
		}
		// D key
		if ((GetKeyState(0x44) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x44;
			
		}
		// E key
		if ((GetKeyState(0x45) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x45;
			
		}
		// F key
		if ((GetKeyState(0x46) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x46;
			
		}
		// G key
		if ((GetKeyState(0x47) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x47;
			
		}
		// H key
		if ((GetKeyState(0x48) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x48;
			
		}
		// I key
		if ((GetKeyState(0x49) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x49;
			
		}
		// J key
		if ((GetKeyState(0x4A) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x4A;
			
		}
		// K key
		if ((GetKeyState(0x4B) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x4B;
			
		}
		// L key
		if ((GetKeyState(0x4C) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x4C;
			
		}
		// M key
		if ((GetKeyState(0x4D) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x4D;
			
		}
		// N key
		if ((GetKeyState(0x4E) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x4E;
			
		}
		// O key
		if ((GetKeyState(0x4F) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x4F;
			
		}
		// P key
		if ((GetKeyState(0x50) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x50;
			
		}
		// Q key
		if ((GetKeyState(0x51) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x51;
			
		}
		// R key
		if ((GetKeyState(0x52) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x52;
			
		}
		// S key
		if ((GetKeyState(0x53) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x53;
			
		}
		// T key
		if ((GetKeyState(0x54) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x54;
			
		}
		// U key
		if ((GetKeyState(0x55) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x55;
			
		}
		// V key
		if ((GetKeyState(0x56) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x56;
			
		}
		// W key
		if ((GetKeyState(0x57) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x57;
			
		}
		// X key
		if ((GetKeyState(0x58) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x58;
			
		}
		// Y key
		if ((GetKeyState(0x59) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x59;
			
		}
		// Z key
		if ((GetKeyState(0x5A) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x5A;
			
		}
		// numpad 0 key
		if ((GetKeyState(0x60) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x60;
			
		}
		// numpad 1 key
		if ((GetKeyState(0x61) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x61;
			
		}
		// numpad 2 key
		if ((GetKeyState(0x62) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x62;
			
		}
		// numpad 3 key
		if ((GetKeyState(0x63) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x63;
			
		}
		// numpad 4 key
		if ((GetKeyState(0x64) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x64;
			
		}
		// numpad 5 key
		if ((GetKeyState(0x65) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x65;
			
		}
		// numpad 6 key
		if ((GetKeyState(0x66) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x66;
			
		}
		// numpad 7 key
		if ((GetKeyState(0x67) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x67;
			
		}
		// numpad 8 key
		if ((GetKeyState(0x68) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x68;
			
		}
		// numpad 9 key
		if ((GetKeyState(0x69) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x69;
			
		}
		// multiply key
		if ((GetKeyState(0x6A) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x6A;
			
		}
		// add key
		if ((GetKeyState(0x6B) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x6B;
			
		}
		// separator key
		if ((GetKeyState(0x6C) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x6C;
			
		}
		// subtract key
		if ((GetKeyState(0x6D) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x6D;
			
		}
		// decimal key
		if ((GetKeyState(0x6E) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x6E;
			
		}
		// divide key
		if ((GetKeyState(0x6F) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x6F;
			
		}
		// f1 key
		if ((GetKeyState(0x70) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x70;
			
		}
		// f2 key
		if ((GetKeyState(0x71) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x71;
			
		}
		// f3 key
		if ((GetKeyState(0x72) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x72;
			
		}
		// f4 key
		if ((GetKeyState(0x73) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x73;
			
		}
		// f5 key
		if ((GetKeyState(0x74) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x74;
			
		}
		// f6 key
		if ((GetKeyState(0x75) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x75;
			
		}
		// f7 key
		if ((GetKeyState(0x76) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x76;
			
		}
		// f8 key
		if ((GetKeyState(0x77) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x77;
			
		}
		// f9 key
		if ((GetKeyState(0x78) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x78;
			
		}
		// f10 key
		if ((GetKeyState(0x79) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x79;
			
		}
		// f11 key
		if ((GetKeyState(0x7A) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x7A;
			
		}
		// f12 key
		if ((GetKeyState(0x7B) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x7B;
			
		}
		// f13 key
		if ((GetKeyState(0x7C) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x7C;
			
		}
		// f14 key
		if ((GetKeyState(0x7D) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x7D;
			
		}
		// f15 key
		if ((GetKeyState(0x7E) & 0x80) != 0)
		{
			lock = false;
			 numb = 0x7E;
			
		}
		// lshift key
		if ((GetKeyState(0xA0) & 0x80) != 0)
		{
			lock = false;
			 numb = 0xA0;
			
		}
		// rshift key
		if ((GetKeyState(0xA1) & 0x80) != 0)
		{
			lock = false;
			 numb = 0xA1;
			
		}
		// lcontrol key
		if ((GetKeyState(0xA2) & 0x80) != 0)
		{
			lock = false;
			 numb = 0xA2;
			
		}
		// rcontrol key
		if ((GetKeyState(0xA3) & 0x80) != 0)
		{
			lock = false;
			 numb = 0xA3;
			
		}
		// lmenu key
		if ((GetKeyState(0xA4) & 0x80) != 0)
		{
			lock = false;
			 numb = 0xA4;
			
		}
		// rmenu key
		if ((GetKeyState(0xA5) & 0x80) != 0)
		{
			lock = false;
			 numb = 0xA5;
			
		}
	}

	std::string keybindfinalpath = loadkeybindfile();
	std::string keybindtemppath = loadkeybindtempfile();
	std::string keybindinipath = loadkeybindinifile();
	std::string keyline, keyline_original;

	std::ofstream mykeyfile;
	mykeyfile.open(keybindtemppath, std::ios::app | std::ios::in);

	std::ifstream myinikeyfile(keybindinipath);
	std::ifstream mykeyfile_original(keybindfinalpath);

	if (myinikeyfile.is_open())
	{
		while (getline(myinikeyfile, keyline))
		{
			if ((keyline.compare(0, 9, "Keybind: ")) == 0)
			{
				mykeyfile << keyline << numb << std::endl;
			}
		}
	}
	if (mykeyfile_original.is_open())
	{
		while (getline(mykeyfile_original, keyline_original))
		{
			if ((keyline_original.compare(0, 26, "Keybind(cancel sentence): ")) == 0)
			{
				mykeyfile << keyline_original << std::endl;
			}
			if ((keyline_original.compare(0, 19, "Keybind(all chat): ")) == 0)
			{
				mykeyfile << keyline_original;
			}
		}
	}

	myinikeyfile.close();
	mykeyfile.close();
	mykeyfile_original.close();

	char* finalkeybindpatharray = new char[keybindfinalpath.length() / sizeof(keybindfinalpath[0]) + 1];
	char* finalkeybindtemppatharray = new char[keybindtemppath.length() / sizeof(keybindtemppath[0]) + 1];

	for (int count(0); count<keybindfinalpath.length() / sizeof(keybindfinalpath[0]); ++count)
	{
		finalkeybindpatharray[count] = keybindfinalpath[count];
	}
	finalkeybindpatharray[keybindfinalpath.length() / sizeof(keybindfinalpath[0])] = '\0';
	for (int count(0); count < keybindtemppath.length() / sizeof(keybindtemppath[0]); ++count)
	{
		finalkeybindtemppatharray[count] = keybindtemppath[count];
	}
	finalkeybindtemppatharray[keybindtemppath.length() / sizeof(keybindtemppath[0])] = '\0';

	remove(finalkeybindpatharray);
	rename(finalkeybindtemppatharray, finalkeybindpatharray);

	delete[] finalkeybindpatharray;
	finalkeybindpatharray = nullptr;
	delete[] finalkeybindtemppatharray;
	finalkeybindtemppatharray = nullptr;
}

void detectCancelKeyPress()
{
	bool lock = true;
	while (lock)
	{
		// backspace key

		if ((GetKeyState(VK_BACK) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x08;

		}
		// tab key
		if ((GetKeyState(VK_TAB) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x09;

		}
		// return key
		if ((GetKeyState(VK_RETURN) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x0D;

		}
		// shift key
		if ((GetKeyState(VK_SHIFT) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x10;

		}
		// control key
		if ((GetKeyState(VK_CONTROL) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x11;

		}
		// alt key
		if ((GetKeyState(VK_MENU) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x12;

		}
		// pause key
		if ((GetKeyState(VK_PAUSE) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x13;

		}
		// caps-lock key
		if ((GetKeyState(VK_CAPITAL) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x14;

		}
		// esc key
		if ((GetKeyState(VK_ESCAPE) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x1B;

		}
		// caps-lock key
		if ((GetKeyState(VK_SPACE) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x20;

		}
		// page-up key
		if ((GetKeyState(VK_PRIOR) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x21;

		}
		// page-down key
		if ((GetKeyState(VK_NEXT) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x22;

		}
		// end key
		if ((GetKeyState(VK_END) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x23;

		}
		// home key
		if ((GetKeyState(VK_HOME) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x24;

		}
		// left-arrow key
		if ((GetKeyState(VK_LEFT) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x25;

		}
		// up-arrow key
		if ((GetKeyState(VK_UP) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x26;

		}
		// right-arrow key
		if ((GetKeyState(VK_RIGHT) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x27;

		}
		// down-arrow key
		if ((GetKeyState(VK_DOWN) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x28;

		}
		// select key
		if ((GetKeyState(VK_SELECT) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x29;

		}
		// print key
		if ((GetKeyState(VK_PRINT) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x2A;

		}
		// execute key
		if ((GetKeyState(VK_EXECUTE) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x2B;

		}
		// pr-screen key
		if ((GetKeyState(VK_SNAPSHOT) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x2C;

		}
		// insert key
		if ((GetKeyState(VK_INSERT) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x2D;

		}
		// delete key
		if ((GetKeyState(VK_DELETE) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x2E;

		}
		// 0 key
		if ((GetKeyState(0x30) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x30;

		}
		// 1 key
		if ((GetKeyState(0x31) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x31;

		}
		// 2 key
		if ((GetKeyState(0x32) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x32;

		}
		// 3 key
		if ((GetKeyState(0x33) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x33;

		}
		// 4 key
		if ((GetKeyState(0x34) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x34;

		}
		// 5 key
		if ((GetKeyState(0x35) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x35;

		}
		// 6 key
		if ((GetKeyState(0x36) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x36;

		}
		// 7 key
		if ((GetKeyState(0x37) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x37;

		}
		// 8 key
		if ((GetKeyState(0x38) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x38;

		}
		// 9 key
		if ((GetKeyState(0x39) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x39;

		}
		// A key
		if ((GetKeyState(0x41) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x41;

		}
		// B key
		if ((GetKeyState(0x42) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x42;

		}
		// C key
		if ((GetKeyState(0x43) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x43;

		}
		// D key
		if ((GetKeyState(0x44) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x44;

		}
		// E key
		if ((GetKeyState(0x45) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x45;

		}
		// F key
		if ((GetKeyState(0x46) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x46;

		}
		// G key
		if ((GetKeyState(0x47) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x47;

		}
		// H key
		if ((GetKeyState(0x48) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x48;

		}
		// I key
		if ((GetKeyState(0x49) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x49;

		}
		// J key
		if ((GetKeyState(0x4A) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x4A;

		}
		// K key
		if ((GetKeyState(0x4B) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x4B;

		}
		// L key
		if ((GetKeyState(0x4C) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x4C;

		}
		// M key
		if ((GetKeyState(0x4D) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x4D;

		}
		// N key
		if ((GetKeyState(0x4E) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x4E;

		}
		// O key
		if ((GetKeyState(0x4F) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x4F;

		}
		// P key
		if ((GetKeyState(0x50) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x50;

		}
		// Q key
		if ((GetKeyState(0x51) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x51;

		}
		// R key
		if ((GetKeyState(0x52) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x52;

		}
		// S key
		if ((GetKeyState(0x53) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x53;

		}
		// T key
		if ((GetKeyState(0x54) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x54;

		}
		// U key
		if ((GetKeyState(0x55) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x55;

		}
		// V key
		if ((GetKeyState(0x56) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x56;

		}
		// W key
		if ((GetKeyState(0x57) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x57;

		}
		// X key
		if ((GetKeyState(0x58) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x58;

		}
		// Y key
		if ((GetKeyState(0x59) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x59;

		}
		// Z key
		if ((GetKeyState(0x5A) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x5A;

		}
		// numpad 0 key
		if ((GetKeyState(0x60) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x60;

		}
		// numpad 1 key
		if ((GetKeyState(0x61) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x61;

		}
		// numpad 2 key
		if ((GetKeyState(0x62) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x62;

		}
		// numpad 3 key
		if ((GetKeyState(0x63) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x63;

		}
		// numpad 4 key
		if ((GetKeyState(0x64) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x64;

		}
		// numpad 5 key
		if ((GetKeyState(0x65) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x65;

		}
		// numpad 6 key
		if ((GetKeyState(0x66) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x66;

		}
		// numpad 7 key
		if ((GetKeyState(0x67) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x67;

		}
		// numpad 8 key
		if ((GetKeyState(0x68) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x68;

		}
		// numpad 9 key
		if ((GetKeyState(0x69) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x69;

		}
		// multiply key
		if ((GetKeyState(0x6A) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x6A;

		}
		// add key
		if ((GetKeyState(0x6B) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x6B;

		}
		// separator key
		if ((GetKeyState(0x6C) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x6C;

		}
		// subtract key
		if ((GetKeyState(0x6D) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x6D;

		}
		// decimal key
		if ((GetKeyState(0x6E) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x6E;

		}
		// divide key
		if ((GetKeyState(0x6F) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x6F;

		}
		// f1 key
		if ((GetKeyState(0x70) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x70;

		}
		// f2 key
		if ((GetKeyState(0x71) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x71;

		}
		// f3 key
		if ((GetKeyState(0x72) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x72;

		}
		// f4 key
		if ((GetKeyState(0x73) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x73;

		}
		// f5 key
		if ((GetKeyState(0x74) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x74;

		}
		// f6 key
		if ((GetKeyState(0x75) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x75;

		}
		// f7 key
		if ((GetKeyState(0x76) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x76;

		}
		// f8 key
		if ((GetKeyState(0x77) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x77;

		}
		// f9 key
		if ((GetKeyState(0x78) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x78;

		}
		// f10 key
		if ((GetKeyState(0x79) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x79;

		}
		// f11 key
		if ((GetKeyState(0x7A) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x7A;

		}
		// f12 key
		if ((GetKeyState(0x7B) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x7B;

		}
		// f13 key
		if ((GetKeyState(0x7C) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x7C;

		}
		// f14 key
		if ((GetKeyState(0x7D) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x7D;

		}
		// f15 key
		if ((GetKeyState(0x7E) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0x7E;

		}
		// lshift key
		if ((GetKeyState(0xA0) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0xA0;

		}
		// rshift key
		if ((GetKeyState(0xA1) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0xA1;

		}
		// lcontrol key
		if ((GetKeyState(0xA2) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0xA2;

		}
		// rcontrol key
		if ((GetKeyState(0xA3) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0xA3;

		}
		// lmenu key
		if ((GetKeyState(0xA4) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0xA4;

		}
		// rmenu key
		if ((GetKeyState(0xA5) & 0x80) != 0)
		{
			lock = false;
			numb_cancel = 0xA5;

		}
	}

	std::string keybindfinalpath = loadkeybindfile();
	std::string keybindtemppath = loadkeybindtempfile();
	std::string keybindinipath = loadkeybindinifile();
	std::string keyline, keyline_original;

	std::ofstream mykeyfile;
	mykeyfile.open(keybindtemppath, std::ios::app | std::ios::in);

	std::ifstream myinikeyfile(keybindinipath);
	std::ifstream mykeyfile_original(keybindfinalpath);

	if (mykeyfile_original.is_open())
	{
		while (getline(mykeyfile_original, keyline_original))
		{
			if ((keyline_original.compare(0, 9, "Keybind: ")) == 0)
			{
				mykeyfile << keyline_original << std::endl;
			}
		}
	}
	if (myinikeyfile.is_open())
	{
		while (getline(myinikeyfile, keyline))
		{
			if ((keyline.compare(0, 26, "Keybind(cancel sentence): ")) == 0)
			{
				mykeyfile << keyline << numb_cancel << std::endl;
			}
		}
	}

	mykeyfile_original.clear();
	mykeyfile_original.seekg(0, mykeyfile_original.beg);

	if (mykeyfile_original.is_open())
	{
		while (getline(mykeyfile_original, keyline_original))
		{
			if ((keyline_original.compare(0, 19, "Keybind(all chat): ")) == 0)
			{
				mykeyfile << keyline_original;
			}
		}
	}

	myinikeyfile.close();
	mykeyfile.close();
	mykeyfile_original.close();

	char* finalkeybindpatharray = new char[keybindfinalpath.length() / sizeof(keybindfinalpath[0]) + 1];
	char* finalkeybindtemppatharray = new char[keybindtemppath.length() / sizeof(keybindtemppath[0]) + 1];

	for (int count(0); count<keybindfinalpath.length() / sizeof(keybindfinalpath[0]); ++count)
	{
		finalkeybindpatharray[count] = keybindfinalpath[count];
	}
	finalkeybindpatharray[keybindfinalpath.length() / sizeof(keybindfinalpath[0])] = '\0';
	for (int count(0); count < keybindtemppath.length() / sizeof(keybindtemppath[0]); ++count)
	{
		finalkeybindtemppatharray[count] = keybindtemppath[count];
	}
	finalkeybindtemppatharray[keybindtemppath.length() / sizeof(keybindtemppath[0])] = '\0';

	remove(finalkeybindpatharray);
	rename(finalkeybindtemppatharray, finalkeybindpatharray);

	delete[] finalkeybindpatharray;
	finalkeybindpatharray = nullptr;
	delete[] finalkeybindtemppatharray;
	finalkeybindtemppatharray = nullptr;
}

void detectAllChatKeyPress()
{
	bool lock = true;
	while (lock)
	{
		// backspace key

		if ((GetKeyState(VK_BACK) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x08;

		}
		// tab key
		if ((GetKeyState(VK_TAB) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x09;

		}
		// return key
		if ((GetKeyState(VK_RETURN) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x0D;

		}
		// shift key
		if ((GetKeyState(VK_SHIFT) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x10;

		}
		// control key
		if ((GetKeyState(VK_CONTROL) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x11;

		}
		// alt key
		if ((GetKeyState(VK_MENU) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x12;

		}
		// pause key
		if ((GetKeyState(VK_PAUSE) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x13;

		}
		// caps-lock key
		if ((GetKeyState(VK_CAPITAL) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x14;

		}
		// esc key
		if ((GetKeyState(VK_ESCAPE) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x1B;

		}
		// caps-lock key
		if ((GetKeyState(VK_SPACE) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x20;

		}
		// page-up key
		if ((GetKeyState(VK_PRIOR) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x21;

		}
		// page-down key
		if ((GetKeyState(VK_NEXT) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x22;

		}
		// end key
		if ((GetKeyState(VK_END) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x23;

		}
		// home key
		if ((GetKeyState(VK_HOME) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x24;

		}
		// left-arrow key
		if ((GetKeyState(VK_LEFT) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x25;

		}
		// up-arrow key
		if ((GetKeyState(VK_UP) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x26;

		}
		// right-arrow key
		if ((GetKeyState(VK_RIGHT) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x27;

		}
		// down-arrow key
		if ((GetKeyState(VK_DOWN) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x28;

		}
		// select key
		if ((GetKeyState(VK_SELECT) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x29;

		}
		// print key
		if ((GetKeyState(VK_PRINT) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x2A;

		}
		// execute key
		if ((GetKeyState(VK_EXECUTE) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x2B;

		}
		// pr-screen key
		if ((GetKeyState(VK_SNAPSHOT) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x2C;

		}
		// insert key
		if ((GetKeyState(VK_INSERT) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x2D;

		}
		// delete key
		if ((GetKeyState(VK_DELETE) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x2E;

		}
		// 0 key
		if ((GetKeyState(0x30) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x30;

		}
		// 1 key
		if ((GetKeyState(0x31) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x31;

		}
		// 2 key
		if ((GetKeyState(0x32) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x32;

		}
		// 3 key
		if ((GetKeyState(0x33) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x33;

		}
		// 4 key
		if ((GetKeyState(0x34) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x34;

		}
		// 5 key
		if ((GetKeyState(0x35) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x35;

		}
		// 6 key
		if ((GetKeyState(0x36) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x36;

		}
		// 7 key
		if ((GetKeyState(0x37) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x37;

		}
		// 8 key
		if ((GetKeyState(0x38) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x38;

		}
		// 9 key
		if ((GetKeyState(0x39) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x39;

		}
		// A key
		if ((GetKeyState(0x41) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x41;

		}
		// B key
		if ((GetKeyState(0x42) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x42;

		}
		// C key
		if ((GetKeyState(0x43) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x43;

		}
		// D key
		if ((GetKeyState(0x44) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x44;

		}
		// E key
		if ((GetKeyState(0x45) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x45;

		}
		// F key
		if ((GetKeyState(0x46) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x46;

		}
		// G key
		if ((GetKeyState(0x47) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x47;

		}
		// H key
		if ((GetKeyState(0x48) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x48;

		}
		// I key
		if ((GetKeyState(0x49) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x49;

		}
		// J key
		if ((GetKeyState(0x4A) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x4A;

		}
		// K key
		if ((GetKeyState(0x4B) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x4B;

		}
		// L key
		if ((GetKeyState(0x4C) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x4C;

		}
		// M key
		if ((GetKeyState(0x4D) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x4D;

		}
		// N key
		if ((GetKeyState(0x4E) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x4E;

		}
		// O key
		if ((GetKeyState(0x4F) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x4F;

		}
		// P key
		if ((GetKeyState(0x50) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x50;

		}
		// Q key
		if ((GetKeyState(0x51) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x51;

		}
		// R key
		if ((GetKeyState(0x52) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x52;

		}
		// S key
		if ((GetKeyState(0x53) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x53;

		}
		// T key
		if ((GetKeyState(0x54) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x54;

		}
		// U key
		if ((GetKeyState(0x55) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x55;

		}
		// V key
		if ((GetKeyState(0x56) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x56;

		}
		// W key
		if ((GetKeyState(0x57) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x57;

		}
		// X key
		if ((GetKeyState(0x58) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x58;

		}
		// Y key
		if ((GetKeyState(0x59) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x59;

		}
		// Z key
		if ((GetKeyState(0x5A) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x5A;

		}
		// numpad 0 key
		if ((GetKeyState(0x60) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x60;

		}
		// numpad 1 key
		if ((GetKeyState(0x61) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x61;

		}
		// numpad 2 key
		if ((GetKeyState(0x62) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x62;

		}
		// numpad 3 key
		if ((GetKeyState(0x63) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x63;

		}
		// numpad 4 key
		if ((GetKeyState(0x64) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x64;

		}
		// numpad 5 key
		if ((GetKeyState(0x65) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x65;

		}
		// numpad 6 key
		if ((GetKeyState(0x66) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x66;

		}
		// numpad 7 key
		if ((GetKeyState(0x67) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x67;

		}
		// numpad 8 key
		if ((GetKeyState(0x68) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x68;

		}
		// numpad 9 key
		if ((GetKeyState(0x69) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x69;

		}
		// multiply key
		if ((GetKeyState(0x6A) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x6A;

		}
		// add key
		if ((GetKeyState(0x6B) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x6B;

		}
		// separator key
		if ((GetKeyState(0x6C) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x6C;

		}
		// subtract key
		if ((GetKeyState(0x6D) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x6D;

		}
		// decimal key
		if ((GetKeyState(0x6E) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x6E;

		}
		// divide key
		if ((GetKeyState(0x6F) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x6F;

		}
		// f1 key
		if ((GetKeyState(0x70) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x70;

		}
		// f2 key
		if ((GetKeyState(0x71) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x71;

		}
		// f3 key
		if ((GetKeyState(0x72) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x72;

		}
		// f4 key
		if ((GetKeyState(0x73) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x73;

		}
		// f5 key
		if ((GetKeyState(0x74) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x74;

		}
		// f6 key
		if ((GetKeyState(0x75) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x75;

		}
		// f7 key
		if ((GetKeyState(0x76) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x76;

		}
		// f8 key
		if ((GetKeyState(0x77) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x77;

		}
		// f9 key
		if ((GetKeyState(0x78) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x78;

		}
		// f10 key
		if ((GetKeyState(0x79) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x79;

		}
		// f11 key
		if ((GetKeyState(0x7A) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x7A;

		}
		// f12 key
		if ((GetKeyState(0x7B) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x7B;

		}
		// f13 key
		if ((GetKeyState(0x7C) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x7C;

		}
		// f14 key
		if ((GetKeyState(0x7D) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x7D;

		}
		// f15 key
		if ((GetKeyState(0x7E) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0x7E;

		}
		// lshift key
		if ((GetKeyState(0xA0) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0xA0;

		}
		// rshift key
		if ((GetKeyState(0xA1) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0xA1;

		}
		// lcontrol key
		if ((GetKeyState(0xA2) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0xA2;

		}
		// rcontrol key
		if ((GetKeyState(0xA3) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0xA3;

		}
		// lmenu key
		if ((GetKeyState(0xA4) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0xA4;

		}
		// rmenu key
		if ((GetKeyState(0xA5) & 0x80) != 0)
		{
			lock = false;
			numb_allchat = 0xA5;

		}
	}

	std::string keybindfinalpath = loadkeybindfile();
	std::string keybindtemppath = loadkeybindtempfile();
	std::string keybindinipath = loadkeybindinifile();
	std::string keyline, keyline_original;

	std::ofstream mykeyfile;
	mykeyfile.open(keybindtemppath, std::ios::app | std::ios::in);

	std::ifstream myinikeyfile(keybindinipath);
	std::ifstream mykeyfile_original(keybindfinalpath);

	if (mykeyfile_original.is_open())
	{
		while (getline(mykeyfile_original, keyline_original))
		{
			if ((keyline_original.compare(0, 9, "Keybind: ")) == 0)
			{
				mykeyfile << keyline_original << std::endl;
			}
			if ((keyline_original.compare(0, 26, "Keybind(cancel sentence): ")) == 0)
			{
				mykeyfile << keyline_original << std::endl;
			}
		}
	}

	if (myinikeyfile.is_open())
	{
		while (getline(myinikeyfile, keyline))
		{
			if ((keyline.compare(0, 19, "Keybind(all chat): ")) == 0)
			{
				mykeyfile << keyline << numb_allchat;
			}
		}
	}

	myinikeyfile.close();
	mykeyfile.close();
	mykeyfile_original.close();

	char* finalkeybindpatharray = new char[keybindfinalpath.length() / sizeof(keybindfinalpath[0]) + 1];
	char* finalkeybindtemppatharray = new char[keybindtemppath.length() / sizeof(keybindtemppath[0]) + 1];

	for (int count(0); count<keybindfinalpath.length() / sizeof(keybindfinalpath[0]); ++count)
	{
		finalkeybindpatharray[count] = keybindfinalpath[count];
	}
	finalkeybindpatharray[keybindfinalpath.length() / sizeof(keybindfinalpath[0])] = '\0';
	for (int count(0); count < keybindtemppath.length() / sizeof(keybindtemppath[0]); ++count)
	{
		finalkeybindtemppatharray[count] = keybindtemppath[count];
	}
	finalkeybindtemppatharray[keybindtemppath.length() / sizeof(keybindtemppath[0])] = '\0';

	remove(finalkeybindpatharray);
	rename(finalkeybindtemppatharray, finalkeybindpatharray);

	delete[] finalkeybindpatharray;
	finalkeybindpatharray = nullptr;
	delete[] finalkeybindtemppatharray;
	finalkeybindtemppatharray = nullptr;
}

void detectOverdriveKeyPress()
{
	bool lock = true;
	while (lock)
	{
		// backspace key

		if ((GetKeyState(VK_BACK) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x08;

		}
		// tab key
		if ((GetKeyState(VK_TAB) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x09;

		}
		// return key
		if ((GetKeyState(VK_RETURN) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x0D;

		}
		// shift key
		if ((GetKeyState(VK_SHIFT) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x10;

		}
		// control key
		if ((GetKeyState(VK_CONTROL) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x11;

		}
		// alt key
		if ((GetKeyState(VK_MENU) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x12;

		}
		// pause key
		if ((GetKeyState(VK_PAUSE) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x13;

		}
		// caps-lock key
		if ((GetKeyState(VK_CAPITAL) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x14;

		}
		// esc key
		if ((GetKeyState(VK_ESCAPE) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x1B;

		}
		// caps-lock key
		if ((GetKeyState(VK_SPACE) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x20;

		}
		// page-up key
		if ((GetKeyState(VK_PRIOR) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x21;

		}
		// page-down key
		if ((GetKeyState(VK_NEXT) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x22;

		}
		// end key
		if ((GetKeyState(VK_END) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x23;

		}
		// home key
		if ((GetKeyState(VK_HOME) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x24;

		}
		// left-arrow key
		if ((GetKeyState(VK_LEFT) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x25;

		}
		// up-arrow key
		if ((GetKeyState(VK_UP) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x26;

		}
		// right-arrow key
		if ((GetKeyState(VK_RIGHT) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x27;

		}
		// down-arrow key
		if ((GetKeyState(VK_DOWN) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x28;

		}
		// select key
		if ((GetKeyState(VK_SELECT) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x29;

		}
		// print key
		if ((GetKeyState(VK_PRINT) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x2A;

		}
		// execute key
		if ((GetKeyState(VK_EXECUTE) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x2B;

		}
		// pr-screen key
		if ((GetKeyState(VK_SNAPSHOT) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x2C;

		}
		// insert key
		if ((GetKeyState(VK_INSERT) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x2D;

		}
		// delete key
		if ((GetKeyState(VK_DELETE) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x2E;

		}
		// 0 key
		if ((GetKeyState(0x30) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x30;

		}
		// 1 key
		if ((GetKeyState(0x31) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x31;

		}
		// 2 key
		if ((GetKeyState(0x32) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x32;

		}
		// 3 key
		if ((GetKeyState(0x33) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x33;

		}
		// 4 key
		if ((GetKeyState(0x34) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x34;

		}
		// 5 key
		if ((GetKeyState(0x35) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x35;

		}
		// 6 key
		if ((GetKeyState(0x36) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x36;

		}
		// 7 key
		if ((GetKeyState(0x37) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x37;

		}
		// 8 key
		if ((GetKeyState(0x38) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x38;

		}
		// 9 key
		if ((GetKeyState(0x39) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x39;

		}
		// A key
		if ((GetKeyState(0x41) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x41;

		}
		// B key
		if ((GetKeyState(0x42) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x42;

		}
		// C key
		if ((GetKeyState(0x43) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x43;

		}
		// D key
		if ((GetKeyState(0x44) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x44;

		}
		// E key
		if ((GetKeyState(0x45) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x45;

		}
		// F key
		if ((GetKeyState(0x46) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x46;

		}
		// G key
		if ((GetKeyState(0x47) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x47;

		}
		// H key
		if ((GetKeyState(0x48) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x48;

		}
		// I key
		if ((GetKeyState(0x49) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x49;

		}
		// J key
		if ((GetKeyState(0x4A) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x4A;

		}
		// K key
		if ((GetKeyState(0x4B) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x4B;

		}
		// L key
		if ((GetKeyState(0x4C) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x4C;

		}
		// M key
		if ((GetKeyState(0x4D) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x4D;

		}
		// N key
		if ((GetKeyState(0x4E) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x4E;

		}
		// O key
		if ((GetKeyState(0x4F) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x4F;

		}
		// P key
		if ((GetKeyState(0x50) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x50;

		}
		// Q key
		if ((GetKeyState(0x51) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x51;

		}
		// R key
		if ((GetKeyState(0x52) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x52;

		}
		// S key
		if ((GetKeyState(0x53) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x53;

		}
		// T key
		if ((GetKeyState(0x54) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x54;

		}
		// U key
		if ((GetKeyState(0x55) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x55;

		}
		// V key
		if ((GetKeyState(0x56) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x56;

		}
		// W key
		if ((GetKeyState(0x57) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x57;

		}
		// X key
		if ((GetKeyState(0x58) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x58;

		}
		// Y key
		if ((GetKeyState(0x59) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x59;

		}
		// Z key
		if ((GetKeyState(0x5A) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x5A;

		}
		// numpad 0 key
		if ((GetKeyState(0x60) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x60;

		}
		// numpad 1 key
		if ((GetKeyState(0x61) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x61;

		}
		// numpad 2 key
		if ((GetKeyState(0x62) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x62;

		}
		// numpad 3 key
		if ((GetKeyState(0x63) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x63;

		}
		// numpad 4 key
		if ((GetKeyState(0x64) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x64;

		}
		// numpad 5 key
		if ((GetKeyState(0x65) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x65;

		}
		// numpad 6 key
		if ((GetKeyState(0x66) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x66;

		}
		// numpad 7 key
		if ((GetKeyState(0x67) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x67;

		}
		// numpad 8 key
		if ((GetKeyState(0x68) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x68;

		}
		// numpad 9 key
		if ((GetKeyState(0x69) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x69;

		}
		// multiply key
		if ((GetKeyState(0x6A) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x6A;

		}
		// add key
		if ((GetKeyState(0x6B) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x6B;

		}
		// separator key
		if ((GetKeyState(0x6C) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x6C;

		}
		// subtract key
		if ((GetKeyState(0x6D) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x6D;

		}
		// decimal key
		if ((GetKeyState(0x6E) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x6E;

		}
		// divide key
		if ((GetKeyState(0x6F) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x6F;

		}
		// f1 key
		if ((GetKeyState(0x70) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x70;

		}
		// f2 key
		if ((GetKeyState(0x71) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x71;

		}
		// f3 key
		if ((GetKeyState(0x72) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x72;

		}
		// f4 key
		if ((GetKeyState(0x73) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x73;

		}
		// f5 key
		if ((GetKeyState(0x74) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x74;

		}
		// f6 key
		if ((GetKeyState(0x75) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x75;

		}
		// f7 key
		if ((GetKeyState(0x76) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x76;

		}
		// f8 key
		if ((GetKeyState(0x77) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x77;

		}
		// f9 key
		if ((GetKeyState(0x78) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x78;

		}
		// f10 key
		if ((GetKeyState(0x79) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x79;

		}
		// f11 key
		if ((GetKeyState(0x7A) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x7A;

		}
		// f12 key
		if ((GetKeyState(0x7B) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x7B;

		}
		// f13 key
		if ((GetKeyState(0x7C) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x7C;

		}
		// f14 key
		if ((GetKeyState(0x7D) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x7D;

		}
		// f15 key
		if ((GetKeyState(0x7E) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0x7E;

		}
		// lshift key
		if ((GetKeyState(0xA0) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0xA0;

		}
		// rshift key
		if ((GetKeyState(0xA1) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0xA1;

		}
		// lcontrol key
		if ((GetKeyState(0xA2) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0xA2;

		}
		// rcontrol key
		if ((GetKeyState(0xA3) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0xA3;

		}
		// lmenu key
		if ((GetKeyState(0xA4) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0xA4;

		}
		// rmenu key
		if ((GetKeyState(0xA5) & 0x80) != 0)
		{
			lock = false;
			numb_overdrive = 0xA5;

		}
	}

	std::string overdrivefinalpath = loadoverdrivefile();
	std::string overdrivetemppath = loadoverdrivetempfile();
	std::string overdriveinipath = loadoverdriveinifile();
	std::string keyline;

	std::ofstream mykeyfile;
	mykeyfile.open(overdrivetemppath, std::ios::app | std::ios::in);

	std::ifstream myinikeyfile(overdriveinipath);

	if (myinikeyfile.is_open())
	{
		while (getline(myinikeyfile, keyline))
		{
			mykeyfile << keyline << numb_overdrive;
		}
	}
	myinikeyfile.close();
	mykeyfile.close();

	char* finalkeybindpatharray = new char[overdrivefinalpath.length() / sizeof(overdrivefinalpath[0]) + 1];
	char* finalkeybindtemppatharray = new char[overdrivetemppath.length() / sizeof(overdrivetemppath[0]) + 1];

	for (int count(0); count<overdrivefinalpath.length() / sizeof(overdrivefinalpath[0]); ++count)
	{
		finalkeybindpatharray[count] = overdrivefinalpath[count];
	}
	finalkeybindpatharray[overdrivefinalpath.length() / sizeof(overdrivefinalpath[0])] = '\0';
	for (int count(0); count < overdrivetemppath.length() / sizeof(overdrivetemppath[0]); ++count)
	{
		finalkeybindtemppatharray[count] = overdrivetemppath[count];
	}
	finalkeybindtemppatharray[overdrivetemppath.length() / sizeof(overdrivetemppath[0])] = '\0';

	remove(finalkeybindpatharray);
	rename(finalkeybindtemppatharray, finalkeybindpatharray);

	delete[] finalkeybindpatharray;
	finalkeybindpatharray = nullptr;
	delete[] finalkeybindtemppatharray;
	finalkeybindtemppatharray = nullptr;
}

// viewKey returns the keybind user entered
int viewKey()
{
	std::string keybindfinalpath = loadkeybindfile();
	std::string key;
	int size;
	int holder;

	char * array_key = nullptr;

	std::ifstream keyfile(keybindfinalpath);

	if (keyfile.is_open())
	{
		while (getline(keyfile, key))
		{
			if ((key.compare(0, 9, "Keybind: ")) == 0)
			{
				size = (key.length() / sizeof(key[0])) - 9;			// size of integer
				array_key = new char[size];
				for (int count(0); count < (size); ++count)
				{
					array_key[count] = key[count + 9];
				}
			}
		}
	}
	keyfile.close();
	sscanf_s(array_key, "%d", &holder);
	delete[] array_key;
	array_key = nullptr;
	return holder;
}

// returns the overdrive keybind user entered
int viewOverdriveKey()
{
	std::string overdrivefinalpath = loadoverdrivefile();
	std::string key;
	int size;
	int holder;

	char * array_key = nullptr;

	std::ifstream keyfile(overdrivefinalpath);

	if (keyfile.is_open())
	{
		while (getline(keyfile, key))
		{
			size = (key.length() / sizeof(key[0])) - 9;			// size of integer
			array_key = new char[size];
			for (int count(0); count < (size); ++count)
			{
				array_key[count] = key[count + 9];
			}
		}
	}
	keyfile.close();
	sscanf_s(array_key, "%d", &holder);
	delete[] array_key;
	array_key = nullptr;
	return holder;
}

// returns the cancel sentence keybind user entered
int viewCancelKey()
{
	std::string keybindfinalpath = loadkeybindfile();
	std::string key;
	int size;
	int holder;

	char * array_key = nullptr;

	std::ifstream keyfile(keybindfinalpath);

	if (keyfile.is_open())
	{
		while (getline(keyfile, key))
		{
			if ((key.compare(0, 26, "Keybind(cancel sentence): ")) == 0)
			{
				size = (key.length() / sizeof(key[0])) - 26;			// size of integer
				array_key = new char[size];
				for (int count(0); count < (size); ++count)
				{
					array_key[count] = key[count + 26];
				}
			}
		}
	}
	keyfile.close();
	sscanf_s(array_key, "%d", &holder);
	delete[] array_key;
	array_key = nullptr;
	return holder;
}

// returns the all chat keybind user entered
int viewAllChatKey()
{
	std::string keybindfinalpath = loadkeybindfile();
	std::string key;
	int size;
	int holder;

	char * array_key = nullptr;

	std::ifstream keyfile(keybindfinalpath);

	if (keyfile.is_open())
	{
		while (getline(keyfile, key))
		{
			if ((key.compare(0, 19, "Keybind(all chat): ")) == 0)
			{
				size = (key.length() / sizeof(key[0])) - 19;			// size of integer
				array_key = new char[size];
				for (int count(0); count < (size); ++count)
				{
					array_key[count] = key[count + 19];
				}
			}
		}
	}
	keyfile.close();
	sscanf_s(array_key, "%d", &holder);
	delete[] array_key;
	array_key = nullptr;
	return holder;
}

std::string loadkeybindfile()
{
	// load keybind
	char exe_path[MAX_PATH];
	char* keybind_path = nullptr;
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

	keybind_path = new char[directorysize + 13 + 1];
	char keybindfilename[15] = "Config/keybind";

	for (int count(0); count < directorysize - 1; ++count)
	{
		keybind_path[count] = exe_path[count];
	}
	for (int count(0); count < 14; ++count)
	{
		keybind_path[directorysize - 1 + count] = keybindfilename[count];
	}
	keybind_path[directorysize + 13] = '\0';

	std::string keybindfinalpath = sconvert(keybind_path, (directorysize + 13 + 1));
	delete[] keybind_path;
	keybind_path = nullptr;
	return keybindfinalpath;
}

std::string loadkeybindinifile()
{
	// load keybindini
	char exe_path[MAX_PATH];
	char* keybindini_path = nullptr;
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

	keybindini_path = new char[directorysize + 17 + 1];
	char pathinifilename[19] = "Config/keybind_ini";

	for (int count(0); count < directorysize - 1; ++count)
	{
		keybindini_path[count] = exe_path[count];
	}
	for (int count(0); count < 18; ++count)
	{
		keybindini_path[directorysize - 1 + count] = pathinifilename[count];
	}
	keybindini_path[directorysize + 17] = '\0';

	std::string keybindinifinalpath = sconvert(keybindini_path, (directorysize + 17 + 1));
	delete[] keybindini_path;
	keybindini_path = nullptr;
	return keybindinifinalpath;
}

std::string loadkeybindtempfile()
{
	// load config
	char exe_path[MAX_PATH];
	char* keybindtemp_path = nullptr;
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

	keybindtemp_path = new char[directorysize + 18 + 1];
	char keybindtempfilename[20] = "Config/keybind_temp";

	for (int count(0); count < directorysize - 1; ++count)
	{
		keybindtemp_path[count] = exe_path[count];
	}
	for (int count(0); count < 19; ++count)
	{
		keybindtemp_path[directorysize - 1 + count] = keybindtempfilename[count];
	}
	keybindtemp_path[directorysize + 18] = '\0';

	std::string keybindtempfinalpath = sconvert(keybindtemp_path, (directorysize + 18 + 1));
	delete[] keybindtemp_path;
	keybindtemp_path = nullptr;
	return keybindtempfinalpath;
}

std::string loadoverdrivefile()
{
	// load keybind
	char exe_path[MAX_PATH];
	char* overdrive_path = nullptr;
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

	overdrive_path = new char[directorysize + 15 + 1];
	char overdrivefilename[17] = "Config/overdrive";

	for (int count(0); count < directorysize - 1; ++count)
	{
		overdrive_path[count] = exe_path[count];
	}
	for (int count(0); count < 16; ++count)
	{
		overdrive_path[directorysize - 1 + count] = overdrivefilename[count];
	}
	overdrive_path[directorysize + 15] = '\0';

	std::string overdrivefinalpath = sconvert(overdrive_path, (directorysize + 15 + 1));
	delete[] overdrive_path;
	overdrive_path = nullptr;
	return overdrivefinalpath;
}

std::string loadoverdriveinifile()
{
	// load keybindini
	char exe_path[MAX_PATH];
	char* overdriveini_path = nullptr;
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

	overdriveini_path = new char[directorysize + 19 + 1];
	char overdriveinifilename[21] = "Config/overdrive_ini";

	for (int count(0); count < directorysize - 1; ++count)
	{
		overdriveini_path[count] = exe_path[count];
	}
	for (int count(0); count < 20; ++count)
	{
		overdriveini_path[directorysize - 1 + count] = overdriveinifilename[count];
	}
	overdriveini_path[directorysize + 19] = '\0';

	std::string overdriveinifinalpath = sconvert(overdriveini_path, (directorysize + 19 + 1));
	delete[] overdriveini_path;
	overdriveini_path = nullptr;
	return overdriveinifinalpath;
}

std::string loadoverdrivetempfile()
{
	// load config
	char exe_path[MAX_PATH];
	char* overdrivetemp_path = nullptr;
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

	overdrivetemp_path = new char[directorysize + 20 + 1];
	char overdrivetempfilename[22] = "Config/overdrive_temp";

	for (int count(0); count < directorysize - 1; ++count)
	{
		overdrivetemp_path[count] = exe_path[count];
	}
	for (int count(0); count < 21; ++count)
	{
		overdrivetemp_path[directorysize - 1 + count] = overdrivetempfilename[count];
	}
	overdrivetemp_path[directorysize + 20] = '\0';

	std::string overdrivetempfinalpath = sconvert(overdrivetemp_path, (directorysize + 20 + 1));
	delete[] overdrivetemp_path;
	overdrivetemp_path = nullptr;
	return overdrivetempfinalpath;
}
