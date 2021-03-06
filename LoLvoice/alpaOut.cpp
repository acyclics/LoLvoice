#include <iostream>
#include <Windows.h>
#include <string>
#include <array>

#include <fstream>

// converts sound buffer from sphinx to pseudo keyboard presses
void alpaOut(char char_array[], int length)
{
	using namespace std;
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	for (int counter = 0; counter < length; ++counter)
	{
		Sleep(1);
		switch (char_array[counter])
		{
			/* Kept in block comment as pocketsphinx does not output decimal, rather English (1 = one)
		case '0':
			ip.ki.wVk = 0x30;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '1':
			ip.ki.wVk = 0x31;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '2':
			ip.ki.wVk = 0x32;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '3':
			ip.ki.wVk = 0x33;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '4':
			ip.ki.wVk = 0x34;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '5':
			ip.ki.wVk = 0x35;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '6':
			ip.ki.wVk = 0x36;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '7':
			ip.ki.wVk = 0x37;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '8':
			ip.ki.wVk = 0x38;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case '9':
			ip.ki.wVk = 0x39;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			*/
		case 'a':
			ip.ki.wVk = 0x41;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'A':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x41;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'b':
			ip.ki.wVk = 0x42;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'B':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x42;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'c':
			ip.ki.wVk = 0x43;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'C':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x43;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'd':
			ip.ki.wVk = 0x44;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'D':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x44;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'e':
			ip.ki.wVk = 0x45;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'E':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x45;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'f':
			ip.ki.wVk = 0x46;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'F':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x46;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'g':
			ip.ki.wVk = 0x47;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'G':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x47;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'h':
			ip.ki.wVk = 0x48;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'H':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x48;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'i':
			ip.ki.wVk = 0x49;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'I':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x49;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'j':
			ip.ki.wVk = 0x4A;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'J':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4A;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'k':
			ip.ki.wVk = 0x4B;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'K':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4B;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'l':
			ip.ki.wVk = 0x4C;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'L':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4C;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'm':
			ip.ki.wVk = 0x4D;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'M':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4D;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'n':
			ip.ki.wVk = 0x4E;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'N':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4E;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'o':
			ip.ki.wVk = 0x4F;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'O':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4F;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'p':
			ip.ki.wVk = 0x50;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'P':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x50;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'q':
			ip.ki.wVk = 0x51;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'Q':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x51;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'r':
			ip.ki.wVk = 0x52;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'R':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x52;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 's':
			ip.ki.wVk = 0x53;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'S':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x53;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 't':
			ip.ki.wVk = 0x54;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'T':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x54;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'u':
			ip.ki.wVk = 0x55;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'U':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x55;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'v':
			ip.ki.wVk = 0x56;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'V':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x56;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'w':
			ip.ki.wVk = 0x57;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'W':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x57;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'x':
			ip.ki.wVk = 0x58;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'X':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x58;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'y':
			ip.ki.wVk = 0x59;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'Y':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x59;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'z':
			ip.ki.wVk = 0x5A;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'Z':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x5A;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case ' ':
			ip.ki.wVk = VK_SPACE;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		}
	}
}

void alpaOut_string(std::string speech)
{
	using namespace std;
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	for (int counter = 0; counter < speech.length() / sizeof(speech[0]); ++counter)
	{
		Sleep(1);
		switch (speech[counter])
		{
			/* Kept in block comment as pocketsphinx does not output decimal, rather English (1 = one)
			case '0':
			ip.ki.wVk = 0x30;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '1':
			ip.ki.wVk = 0x31;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '2':
			ip.ki.wVk = 0x32;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '3':
			ip.ki.wVk = 0x33;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '4':
			ip.ki.wVk = 0x34;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '5':
			ip.ki.wVk = 0x35;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '6':
			ip.ki.wVk = 0x36;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '7':
			ip.ki.wVk = 0x37;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '8':
			ip.ki.wVk = 0x38;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			case '9':
			ip.ki.wVk = 0x39;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
			*/
		case 'a':
			ip.ki.wVk = 0x41;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'A':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x41;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'b':
			ip.ki.wVk = 0x42;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'B':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x42;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'c':
			ip.ki.wVk = 0x43;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'C':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x43;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'd':
			ip.ki.wVk = 0x44;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'D':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x44;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'e':
			ip.ki.wVk = 0x45;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'E':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x45;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'f':
			ip.ki.wVk = 0x46;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'F':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x46;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'g':
			ip.ki.wVk = 0x47;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'G':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x47;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'h':
			ip.ki.wVk = 0x48;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'H':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x48;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'i':
			ip.ki.wVk = 0x49;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'I':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x49;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'j':
			ip.ki.wVk = 0x4A;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'J':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4A;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'k':
			ip.ki.wVk = 0x4B;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'K':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4B;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'l':
			ip.ki.wVk = 0x4C;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'L':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4C;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'm':
			ip.ki.wVk = 0x4D;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'M':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4D;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'n':
			ip.ki.wVk = 0x4E;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'N':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4E;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'o':
			ip.ki.wVk = 0x4F;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'O':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x4F;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'p':
			ip.ki.wVk = 0x50;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'P':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x50;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'q':
			ip.ki.wVk = 0x51;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'Q':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x51;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'r':
			ip.ki.wVk = 0x52;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'R':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x52;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 's':
			ip.ki.wVk = 0x53;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'S':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x53;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 't':
			ip.ki.wVk = 0x54;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'T':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x54;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'u':
			ip.ki.wVk = 0x55;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'U':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x55;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'v':
			ip.ki.wVk = 0x56;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'V':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x56;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'w':
			ip.ki.wVk = 0x57;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'W':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x57;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'x':
			ip.ki.wVk = 0x58;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'X':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x58;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'y':
			ip.ki.wVk = 0x59;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'Y':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x59;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'z':
			ip.ki.wVk = 0x5A;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case 'Z':
			ip.ki.wVk = VK_SHIFT;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			Sleep(1);
			ip.ki.wVk = 0x5A;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		case ' ':
			ip.ki.wVk = VK_SPACE;
			ip.ki.dwFlags = 0;
			SendInput(1, &ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
			break;
		}
	}
}

void typeAllChat()
{
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	// slash
	ip.ki.wVk = VK_DIVIDE;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	Sleep(1);

	// a
	ip.ki.wVk = 0x41;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	Sleep(1);


	// l
	ip.ki.wVk = 0x4C;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	Sleep(1);

	// l
	ip.ki.wVk = 0x4C;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	Sleep(1);

	// space
	ip.ki.wVk = VK_SPACE;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	Sleep(1);
}