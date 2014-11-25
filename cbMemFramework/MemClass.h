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


class Mem {


private:
	void init_function();
	void finalize_function();

	GameProcess gp;

protected:
	DWORD getBaseAddress(HWND window, DWORD pid);


public:
	Mem(GameProcess& process);
	~Mem();




	template<typename T>
	T ReadMemory(DWORD address){
		DWORD base = baseaddr + address;

	}

	template<typename T>
	T WriteMemory(DWORD address, const T& value){

	}




};