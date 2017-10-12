#pragma once
#include <openfilesheaders.h>

using namespace std;

LPCTSTR steampath = TEXT("E:/Steam/Steam.exe");

void opensteam() {
	startup(steampath);
}