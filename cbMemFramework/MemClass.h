#pragma once

#include <Windows.h>
#include <TlHelp32.h> 
#include <memory>
#include <iostream>
#include "GameProcess.h"
using namespace std;





enum OPERATOR {
	ADD,
	SUB,
	DIV,
	MUL,
	OR,
	AND,
	XOR,
	XAND,
	SHIFT_L,
	SHIFT_R
};


class MemoryFramework {


private:
	void init_function();
	void finalize_function();

	GameProcess gp;



public:
	MemoryFramework(GameProcess& process);
	MemoryFramework();
	~MemoryFramework();



	template<typename T>
	T ReadMemory(DWORD address, int len){
		
		DWORD value;
		LPVOID buffer = NULL;
		T ret_value;

		if (ReadProcessMemory(gp.getGameHandle(), (LPVOID)address, buffer, len, 0)){
			ret_value = dynamic_cast<T>(buffer);
			return ret_value;
		}

		return NULL;

	}

	template<typename T>
	T WriteMemory(DWORD address, const T& value){

	}




};