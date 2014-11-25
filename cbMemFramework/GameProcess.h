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
		int tries = 10;


		while (!found){
			game_window = FindWindow(NULL, procname);

			if (game_window || tries < 1){
				found = true;
			}

			// not flood
			
			PRINT_DEBUG_P("Process Not Found - Tries: ", tries);
			::Sleep(1000);
			--tries;
		}

		/*
		  when the loop breaks means found a window!
		  so we store the PID of the process in pid variable
		*/
		if (found) 	GetWindowThreadProcessId(game_window, &pid);

		// returns true/false if found a process 
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

