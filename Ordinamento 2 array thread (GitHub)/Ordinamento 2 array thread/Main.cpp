/**
@author Fiordi Stefano
@date 21/09/2017
Ordinamento di due vettori dichiarati nel main con 2 thread utilizzando un'unica funzione
*/

#include<iostream>
#include<Windows.h>
#include<process.h>
#include<time.h>
#include"Fiordi.h"
#include"Bardazzi.h"
#include"dipirro.h"
#include"Berlincioni.h"
#include"DiLuigi.h" 
#include"Fiasconi.h"
#include"Pandolfini.h"

using namespace std;

/**
Funzione main del programma nella quale vengono lanciati i thread
*/
void main()
{
	srand(time(NULL));
	int iV[100], iW[100];
	unsigned threadid;
	HANDLE H1Bardazzi, H2Bardazzi, H1dipirro, H2dipirro;
	int V1Bardazzi[100];
	int V2Bardazzi[100];
	int V1dipirro[100];
	int V2dipirro[100];
	int iBerlincioni1[100], iBerlincioni2[100];
	int V1Fiasconi[100], V2Fiasconi[100];
	int V1Pandolfini[100]
	int V2Pandolfini[100]
	//Var Di Luigi
	int V1_DiLuigi[100];
	int V2_DiLuigi[100];
	HANDLE T1_DL, T2_DL;	

	for (int i = 0; i < 100; i++)
	{
		iV[i] = rand() % 1000 + 1;
		iW[i] = rand() % 1000 + 1;
		V1Bardazzi[i] = rand() % 1000 + 1;
		V2Bardazzi[i] = rand() % 1000 + 1;
		V1dipirro[i] = rand() % 1000 + 1;
		V2dipirro[i] = rand() % 1000 + 1;
		iBerlincioni1[i] = rand() % 1000 + 1;
		iBerlincioni2[i] = rand() % 1000 + 1;
		V1_DiLuigi[i] = rand() % 1000 + 1;
		V2_DiLuigi[i] = rand() % 1000 + 1;
		V1Fiasconi[i] = rand() % 1000 + 1;
		V2Fiasconi[i] = rand() % 1000 + 1;
		V1Pandolfini[i] = rand() % 1000 + 1;
		V2Pandolfini[i] = rand() % 1000 + 1;

	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perché quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non è più possibile chiudere l'handle del relativo thread
	HANDLE hOrd1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE hOrd2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iW, 0, &threadid); /// Lancio del secondo thread

	H1Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V1Bardazzi);
	H2Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V2Bardazzi);
	
	H1dipirro = (HANDLE)_beginthreadex(NULL, 0, &ord_dipirro, V1dipirro, 0,(void*)V1dipirro);
	H2dipirro = (HANDLE)_beginthreadex(NULL, 0, &ord_dipirro, V2dipirro, 0,(void*)V2dipirro);
	
	
	HANDLE hBerlincioni1 = (HANDLE)_beginthreadex(NULL, 0, &Berli, iBerlincioni1, 0, &threadid);
	HANDLE hBerlincioni2 = (HANDLE)_beginthreadex(NULL, 0, &Berli, iBerlincioni2, 0, &threadid);

	HANDLE h1Fiasconi = (HANDLE)_beginthread(&Ordina, 0, V1Fiasconi);
	HANDLE h2Fiasconi = (HANDLE)_beginthread(&Ordina, 0, V2Fiasconi);

	HANDLE Pandolfinith1 = (HANDLE)_beginthreadex(NULL, 0, &ordinamento, V1Panolfini, 0, &threadid);
	HANDLE Pandolfinith2 = (HANDLE)_beginthreadex(NULL, 0, &ordinamento, V2Pandolfini, 0, &threadid);
	//Di Luigi - Start
	T1_DL = (HANDLE)_beginthread(&Thread_DiLuigi, 0, (void*)V1_DiLuigi);
	T2_DL = (HANDLE)_beginthread(&Thread_DiLuigi, 0, (void*)V2_DiLuigi);	

	
	WaitForSingleObject(H1dipirro, INFINITE);
	WaitForSingleObject(H2dipirro, INFINITE);
	CloseHandle(H1dipirro);
	CloseHandle(H2dipirro);

	//Di Luigi - End
	WaitForSingleObject(T1_DL, INFINITE);
	WaitForSingleObject(T2_DL, INFINITE);
	CloseHandle(T1_DL);
	CloseHandle(T2_DL);
	
	WaitForSingleObject(H1Bardazzi, INFINITE);
	WaitForSingleObject(H2Bardazzi, INFINITE);


	WaitForSingleObject(hOrd1, INFINITE);
	WaitForSingleObject(hOrd2, INFINITE);
	CloseHandle(hOrd1);
	CloseHandle(hOrd2);
	
	
	WaitForSingleObject(hBerlincioni1, INFINITE);
	WaitForSingleObject(hBerlincioni2, INFINITE);
	CloseHandle(hBerlincioni1);
	CloseHandle(hBerlincioni2);

	WaitForSingleObject(h1Fiasconi, INFINITE);
	WaitForSingleObject(h2Fiasconi, INFINITE);

	WaitForSingleObject(Pandolfinith1, INFINITE);
	WaitForSingleObject(Pandolfinith2, INFINITE);
	CloseHandle((Pandolfinith1);
	CloseHandle((Pandolfinith2);

	for (int i = 0; i < 100; i++)
	{
		cout << "iV[" << i << "] = " << iV[i] << "    | iW[" << i << "] = " << iW[i] << endl;

	}

	for (int i = 0; i < 100; i++)
	{
	
		cout << "V1Bardazzi[" << i << "] = " << V1Bardazzi[i] << "    | V2Bardazzi[" << i << "] = " << V2Bardazzi[i] << endl;
	}
	
	for (int i = 0; i < 100; i++)
	{
	
		cout << "V1-DiPirro[" << i << "] = " << V1dipirro[i] << "    | V2-DiPirro[" << i << "] = " << V2dipirro[i] << endl;
	}
	
	for (int i = 0; i < 100; i++)
	{

		cout << "iBerlincioni1[" << i << "] = " << iBerlincioni1[i] << "    | iBerlincioni2[" << i << "] = " << iBerlincioni2[i] << endl;
	}
	
	//Di Luigi - Vid
	for (int i = 0; i < 100; i++)
	{	
		cout << "V1_DiLuigi [" << i << "] = " << V1_DiLuigi[i] << "    | V2_DiLuigi [" << i << "] = " << V2_DiLuigi[i] << endl;
	}

	for (int i = 0; i < 100; i++)
	{
		cout << "V1Fiasconi [" << i << "] = " << V1Fiasconi[i] << "    | V2Fiasconi[" << i << "] = " << V2Fiasconi[i] << endl;
	}
	for (int i = 0; i < 100; i++)
	{

		cout << "V1Pandolfini[" << i << "] = " << V1Pandolfini[i] << "    | V2Pandolfini[" << i << "] = " << V2Pandolfini[i] << endl;
	}
	system("PAUSE");

}
