#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>


/*
*		
*			Funcionamento do programa:
*			Lista os processos do Windows Aberto e
* 
*/


using namespace std;


void ListProcess() {
	HANDLE pHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);


	if (pHandle == INVALID_HANDLE_VALUE) {
		cout << "Erro Encontrado! ";
		exit(-1);
	}
	PROCESSENTRY32 p32;
	p32.dwSize = sizeof(PROCESSENTRY32);


	if (Process32First(pHandle, &p32)) {
		wcout << p32.szExeFile << endl;
	}

	while (Process32Next(pHandle, &p32)) {
		
		wcout << p32.szExeFile << endl;

	}
	CloseHandle(pHandle);
}
void OpenIdProcess(string x,int qtd) {
	string exe = ".exe";
	string comand = "start " +x + exe;
	const char* comand2 = comand.c_str();
	
	for (auto i = 0; i < qtd; i++) {
		system(comand2);
	}
	

	


}


int main() {
	setlocale(LC_ALL, "portuguese");
	char s = 's';
	while (s == 's') {
		string id;
		int qtd;
		ListProcess();
		cout << "Digite O processo que queira Executar e quantas vezes deseja executar ele: Caso não deseja abrir nenhum digite 0 : ";
		cin >> id;
		if (id == "0") {
			exit(-1);
		}
		cin >> qtd;
		const char* x = id.c_str();	
		OpenIdProcess(x,qtd);
		cout << "\n\nGostaria de abrir outro processo? ";
		cin >> s;
		system("cls");
	}

		
	return 0;
}