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
	HANDLE game_handle;

	DWORD getBaseAddress(HWND window, DWORD pid);

public:
	GameProcess();
	~GameProcess();


	bool LoadProcess(LPCWSTR procname);
	void initProcess();



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

	DWORD processBaseAddr(){
		return base_address;
	}

	HANDLE getGameHandle(){
		return game_handle;
	}

	





};

