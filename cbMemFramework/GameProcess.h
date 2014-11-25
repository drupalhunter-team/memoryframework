#pragma once

#include <Windows.h>
#include <TlHelp32.h> 
#include <memory>
#include <iostream>
#include "Global.h"
using namespace std;

class GameProcess
{

private:
	DWORD pid;
	HWND game_window;
	DWORD base_address;

public:
	GameProcess();
	~GameProcess();


	bool LoadProcess(LPCWSTR procname){
		bool found = false;

		while (!found){
			game_window = FindWindow(NULL, procname);

			if (game_window){
				found = true;
			}

			// not flood
			GetWindowThreadProcessId(game_window, &pid);
			PRINT_DEBUG("Process Not Found");
			::Sleep(400);
		}




		return found;
	}


	DWORD Pid(){
		return pid;
	}

	void Pid(DWORD val){
		pid = val;
	}


	HWND Window(){
		return game_window;
	}

	void Window(HWND window){
		game_window = window;
	}



};

