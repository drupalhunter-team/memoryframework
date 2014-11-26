#include "GameProcess.h"
#include "MemClass.h"
#include "Global.h"

#include <cstring>

int main(int argc, char *argv[]){

	GameProcess game;
	if (game.LoadProcess(L"Sem Título - Bloco de Notas")){
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
	char c;
	

	while (1){
		c = memoryhandler.ReadMemory<char>(con_text);
		

	}
	//memcpy(&c, )
	//strcpy(texto, memoryhandler.ReadMemory<char*>(con_text));

	//cout << memoryhandler.ReadMemory<char*>(con_text);
	
		//cerr << texto << endl;
	


	return 0;
}