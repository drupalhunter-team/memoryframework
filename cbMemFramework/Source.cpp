#include "GameProcess.h"
#include "MemClass.h"
#include "Global.h"

#include <cstring>

int main(int argc, char *argv[]){

	GameProcess game;
	if (game.LoadProcess(L"AprQ2")){
		game.initProcess();
	}
	else {
		PRINT_DEBUG("Fatal Error");
		exit(0);
	}
	


	MemoryFramework memoryhandler(game);
	

	//memoryhandler.ReadMemory<char*>()


	DWORD con_text = game.processBaseAddr() + 0x004C1050;
	
	DWORD result = NULL;
	char text[16];
	ZeroMemory(&text, 16);

	while (1){
		result = memoryhandler.ReadMemory(con_text);
		memmove(&text, (LPVOID)&result, sizeof(result) + 1);
		//memcpy(&text,(LPVOID)&result, 14);

	}
	//memcpy(&c, )
	//strcpy(texto, memoryhandler.ReadMemory<char*>(con_text));

	//cout << memoryhandler.ReadMemory<char*>(con_text);
	
		//cerr << texto << endl;
	


	return 0;
}