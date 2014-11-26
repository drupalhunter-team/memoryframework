#include "GameProcess.h"


GameProcess::GameProcess()
{
}


GameProcess::~GameProcess()
{
}



bool GameProcess::LoadProcess(LPCWSTR procname){
	bool found = false;
	int tries = 10;


	while (1){
		game_window = FindWindow(NULL, procname);

		if (game_window){
			found = true;
			break;
		}

		if (tries < 1){
			break;
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
	if (found){
		PRINT_DEBUG("Process Found!!");
		GetWindowThreadProcessId(game_window, &pid);
		base_address = getBaseAddress(game_window, pid);
		PRINT_DEBUG_P("Base Address: ", base_address);
	}
	// returns true/false if found a process 
	return found;
}


void GameProcess::initProcess(){
	
		game_handle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_QUERY_INFORMATION | PROCESS_CREATE_THREAD, 0, pid);

		if (!game_handle){
			PRINT_DEBUG("initProcess(): Failed to Open Process");
	}
}



DWORD GameProcess::getBaseAddress(HWND window, DWORD pid){
	MODULEENTRY32 module;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	module.dwSize = sizeof(MODULEENTRY32);
	Module32First(snapshot, &module);
	DWORD base_address = (DWORD)module.modBaseAddr;

	return base_address;


}