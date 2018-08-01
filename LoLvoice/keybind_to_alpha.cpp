#include <Windows.h>

// integer (stored in keybind file) to keyboard key as keybind is stored in decimal
LPCTSTR intToKey(int hex)
{
	switch(hex)

	{
		// backspace key
	
		case 8:
			return L"backspace";
			break;
		
		// tab key
		case 9:
			return L"tab";
			break;

		// return key
		case 13:
			return L"return";
			break;

		// shift key
		case 16:
			return L"shift";
			break;

		// control key
		case 17:
			return L"control";
			break;

		// alt key
		case 18:
			return L"alt";
			break;

		// pause key
		case 19:
			return L"pause";
			break;

		// caps-lock key
		case 20:
			return L"caps-lock";
			break;

		// esc key
		case 27:
			return L"esc";
			break;

		// spacebar key
		case 32:
			return L"spacebar";
			break;

		// page-up key
		case 33:
			return L"page-up";
			break;

		// page-down key
		case 34:
			return L"page-down";
			break;

		// end key
		case 35:
			return L"end";
			break;

		// home key
		case 36:
			return L"home";
			break;

		// left-arrow key
		case 37:
			return L"left-arrow";
			break;

		// up-arrow key
		case 38:
			return L"up-arrow";
			break;

		// right-arrow key
		case 39:
			return L"right-arrow";
			break;

		// down-arrow key
		case 40:
			return L"down-arrow";
			break;

		// select key
		case 41:
			return L"select";
			break;

		// print key
		case 42:
			return L"print";
			break;

		// execute key
		case 43:
			return L"execute";
			break;

		// print-screen key
		case 44:
			return L"prt-sc";
			break;

		// insert key
		case 45:
			return L"insert";
			break;

		// delete key
		case 46:
			return L"delete";
			break;

		// 0 key
		case 48:
			return L"0";
			break;

		// 1 key
		case 49:
			return L"1";
			break;

		// 2 key
		case 50:
			return L"2";
			break;

		// 3 key
		case 51:
			return L"3";
			break;

		// 4 key
		case 52:
			return L"4";
			break;

		// 5 key
		case 53:
			return L"5";
			break;

		// 6 key
		case 54:
			return L"6";
			break;

		// 7 key
		case 55:
			return L"7";
			break;

		// 8 key
		case 56:
			return L"8";
			break;

		// 9 key
		case 57:
			return L"9";
			break;

		// A key
		case 65:
			return L"A";
			break;

		// B key
		case 66:
			return L"B";
			break;

		// C key
		case 67:
			return L"C";
			break;

		// D key
		case 68:
			return L"D";
			break;

		// E key
		case 69:
			return L"E";
			break;

		// F key
		case 70:
			return L"F";
			break;

		// G key
		case 71:
			return L"G";
			break;

		// H key
		case 72:
			return L"H";
			break;

		// I key
		case 73:
			return L"I";
			break;

		// J key
		case 74:
			return L"J";
			break;

		// K key
		case 75:
			return L"K";
			break;

		// L key
		case 76:
			return L"L";
			break;

		// M key
		case 77:
			return L"M";
			break;

		// N key
		case 78:
			return L"N";
			break;

		// O key
		case 79:
			return L"O";
			break;

		// P key
		case 80:
			return L"P";
			break;

		// Q key
		case 81:
			return L"Q";
			break;
	
		// R key
		case 82:
			return L"R";
			break;

		// S key
		case 83:
			return L"S";
			break;

		// T key
		case 84:
			return L"T";
			break;

		// U key
		case 85:
			return L"U";
			break;

		// V key
		case 86:
			return L"V";
			break;

		// W key
		case 87:
			return L"W";
			break;

		// X key
		case 88:
			return L"X";
			break;

		// Y key
		case 89:
			return L"Y";
			break;

		// Z key
		case 90:
			return L"Z";
			break;

		// numpad 0 key
		case 96:
			return L"Num-0";
			break;

		// numpad 1 key
		case 97:
			return L"Num-1";
			break;

		// numpad 2 key
		case 98:
			return L"Num-2";
			break;

		// numpad 3 key
		case 99:
			return L"Num-3";
			break;

		// numpad 4 key
		case 100:
			return L"Num-4";
			break;

		// numpad 5 key
		case 101:
			return L"Num-5";
			break;

		// numpad 6 key
		case 102:
			return L"Num-6";
			break;

		// numpad 7 key
		case 103:
			return L"Num-7";
			break;

		// numpad 8 key
		case 104:
			return L"Num-8";
			break;

		// numpad 9 key
		case 105:
			return L"Num-9";
			break;

		// multiply key
		case 106:
			return L"*";
			break;

		// add key
		case 107:
			return L"+";
			break;

		// separator key
		case 108:
			return L"-";
			break;

		// subtract key
		case 109:
			return L"-";
			break;

		// decimal key
		case 110:
			return L".";
			break;

		// divide key
		case 111:
			return L"/";
			break;

		// f1 key
		case 112:
			return L"f1";
			break;

		// f2 key
		case 113:
			return L"f2";
			break;

		// f3 key
		case 114:
			return L"f3";
			break;

		// f4 key
		case 115:
			return L"f4";
			break;

		// f5 key
		case 116:
			return L"f5";
			break;

		// f6 key
		case 117:
			return L"f6";
			break;

		// f7 key
		case 118:
			return L"f7";
			break;

		// f8 key
		case 119:
			return L"f8";
			break;

		// f9 key
		case 120:
			return L"f9";
			break;

		// f10 key
		case 121:
			return L"f10";
			break;

		// f11 key
		case 122:
			return L"f11";
			break;

		// f12 key
		case 123:
			return L"f12";
			break;

		// f13 key
		case 124:
			return L"f13";
			break;

		// f14 key
		case 125:
			return L"f14";
			break;

		// f15 key
		case 126:
			return L"f15";
			break;

		// lshift key
		case 160:
			return L"lshift";
			break;

		// rshift key
		case 161:
			return L"rshift";
			break;

		// lcontrol key
		case 162:
			return L"lcontrol";
			break;

		// rcontrol key
		case 163:
			return L"rcontrol";
			break;

		// lmenu key
		case 164:
			return L"lmenu";
			break;

		// rmenu key
		case 165:
			return L"rmenu";
			break;
	}
}