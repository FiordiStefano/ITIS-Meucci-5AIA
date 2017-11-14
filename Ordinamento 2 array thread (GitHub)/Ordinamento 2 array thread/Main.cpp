/**
@author Fiordi Stefano
@date 21/09/2017
Ordinamento di due vettori dichiarati nel main con 2 thread utilizzando un'unica funzione

Questo programma non  fa  proprio schifo ma e' proprio un bel programmino

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
#include"franchi.h"
#include"Fossati.h"
#include"Costanzo.h"
#include"comparini.h"
#include"Fantoni.h"
#include "Fodde.h"
#include "Poneti.h"
using namespace std;

/**
Funzione main del programma nella quale vengono lanciati i thread
*/
void main()
{
	srand(time(NULL));
	int iV[100], iW[100];
	unsigned threadid;
	//Handle Bardazzi e Di Pirro
	HANDLE H1Bardazzi, H2Bardazzi, H1dipirro, H2dipirro;
	int V1Bardazzi[100];
	int V2Bardazzi[100];
	//vettori Di Pirro
	int V1dipirro[100];
	int V2dipirro[100];
	int iBerlincioni1[100], iBerlincioni2[100];
	int V1Fiasconi[100], V2Fiasconi[100];
	int V1Pandolfini[100];
	int V2Pandolfini[100];
	//Var Di Luigi
	int V1_DiLuigi[100];
	int V2_DiLuigi[100];
	int V1Franchi[100];
	int V2Franchi[100];
	int iV_Fossati1[100], iV_Fossati2[100];
	int iV_Costanzo1[100], iV_Costanzo2[100];
	int iV_Compa1[100], iV_Compa2[100];
	int V1Fantoni[100];
	int V2Fantoni[100];
	int V1Fodde[100];
	int V2Fodde[100];
	int iPoneti1[100];
	int iPoneti2[100];


	HANDLE T1_DL, T2_DL;	

	for (int i = 0; i < 100; i++)
	{
		iV[i] = rand() % 1000 + 1;
		iW[i] = rand() % 1000 + 1;
		V1Bardazzi[i] = rand() % 1000 + 1;
		V2Bardazzi[i] = rand() % 1000 + 1;
		//inizializzazione vettori Di Pirro con valori randomici
		V1dipirro[i] = rand() % 1000 + 1;
		V2dipirro[i] = rand() % 1000 + 1;
		iBerlincioni1[i] = rand() % 1000 + 1;
		iBerlincioni2[i] = rand() % 1000 + 1;
		V1_DiLuigi[i] = rand() % 1000 + 1; //Compilamento del Vettore V1 con valori random da 1 a 1000
		V2_DiLuigi[i] = rand() % 1000 + 1; //Compilamento del Vettore V2 con valori random da 1 a 1000
		V1Fiasconi[i] = rand() % 1000 + 1;
		V2Fiasconi[i] = rand() % 1000 + 1;
		V1Pandolfini[i] = rand() % 1000 + 1;
		V2Pandolfini[i] = rand() % 1000 + 1;
		V1Franchi[i] = rand() % 1000 + 1;
		V2Franchi[i] = rand() % 1000 + 1;
		iV_Fossati1[i] = rand() % 1000 + 1;
		iV_Fossati2[i] = rand() % 1000 + 1;
		iV_Costanzo1[i] = rand() % 1000 + 1;
		iV_Costanzo2[i] = rand() % 1000 + 1;
		iV_Compa1[i] = rand() % 1000 + 1;
		iV_Compa2[i] = rand() % 1000 + 1;
		V1Fantoni[i] = rand() % 1000 + 1;
		V2Fantoni[i] = rand() % 1000 + 1;
		V1Fodde[i] = rand() % 1000 + 1;
		V2Fodde[i] = rand() % 1000 + 1;

		iPoneti1[i] = rand() % 1000 + 1;
		iPoneti2[i] = rand() % 1000 + 1;
	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perché quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non è più possibile chiudere l'handle del relativo thread
	HANDLE hOrd1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE hOrd2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iW, 0, &threadid); /// Lancio del secondo thread

	H1Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V1Bardazzi);
	H2Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V2Bardazzi);
	
	//faccio partire i thread di Di Pirro
	H1dipirro = (HANDLE)_beginthreadex(NULL, 0, &ord_dipirro, V1dipirro, 0,&threadid);
	H2dipirro = (HANDLE)_beginthreadex(NULL, 0, &ord_dipirro, V2dipirro, 0,&threadid);
	
	
	HANDLE hBerlincioni1 = (HANDLE)_beginthreadex(NULL, 0, &Berli, iBerlincioni1, 0, &threadid);
	HANDLE hBerlincioni2 = (HANDLE)_beginthreadex(NULL, 0, &Berli, iBerlincioni2, 0, &threadid);

	HANDLE h1Fiasconi = (HANDLE)_beginthread(&Ordina, 0, V1Fiasconi);
	HANDLE h2Fiasconi = (HANDLE)_beginthread(&Ordina, 0, V2Fiasconi);

	HANDLE Pandolfinith1 = (HANDLE)_beginthreadex(NULL, 0, &ordinamento, V1Pandolfini, 0, &threadid);
	HANDLE Pandolfinith2 = (HANDLE)_beginthreadex(NULL, 0, &ordinamento, V2Pandolfini, 0, &threadid);
	//Di Luigi - Start
	T1_DL = (HANDLE)_beginthreadex(NULL, 0, &Thread_DiLuigi, (void*)V1_DiLuigi, 0, &threadid); //Dichiarazione per l' inizzazione del Thread per l' ordinamento del Vettore V1_DiLuigi
	T2_DL = (HANDLE)_beginthreadex(NULL, 0, &Thread_DiLuigi, (void*)V2_DiLuigi, 0, &threadid); //Dichiarazione per l' inizzazione del Thread per l' ordinamento del Vettore V2_DiLuigi

	HANDLE h1Franchi = (HANDLE)_beginthreadex(NULL, 0, ordinafranchi, V1Franchi, 0, &threadid);
	HANDLE h2Franchi = (HANDLE)_beginthreadex(NULL, 0, ordinafranchi, V2Franchi, 0, &threadid);


	HANDLE hFossati1 = (HANDLE)_beginthreadex(NULL, 0, &FossatiOrd, iV_Fossati1, 0, &threadid);
	HANDLE hFossati2 = (HANDLE)_beginthreadex(NULL, 0, &FossatiOrd, iV_Fossati2, 0, &threadid);
	HANDLE hCostanzo1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdCostanzo, iV_Costanzo1, 0, &threadid);
	HANDLE hCostanzo2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdCostanzo, iV_Costanzo2, 0, &threadid);
	HANDLE hCompa1 = (HANDLE)_beginthreadex(NULL, 0, &ordinaC, iV_Compa1, 0, &threadid);
	HANDLE hCompa2 = (HANDLE)_beginthreadex(NULL, 0, &ordinaC, iV_Compa2, 0, &threadid);
	
	HANDLE H1Fantoni = (HANDLE)_beginthreadex(NULL, 0, FantoniF, V1Fantoni, 0, &threadid);
	HANDLE H2Fantoni = (HANDLE)_beginthreadex(NULL, 0, FantoniF, V2Fantoni, 0, &threadid);

	HANDLE H1Fodde = (HANDLE)_beginthreadex(NULL, 0, FoddeF, V1Fodde, 0, &threadid);
	HANDLE H2Fodde = (HANDLE)_beginthreadex(NULL, 0, FoddeF, V2Fodde, 0, &threadid);

	HANDLE h1Poneti = (HANDLE)_beginthreadex(NULL, 0, &threadPoneti, iPoneti1, 0, &threadid);
	HANDLE h2Poneti = (HANDLE)_beginthreadex(NULL, 0, &threadPoneti, iPoneti2, 0, &threadid);


	//Aspetto la fine dei thread e chiudo gli handle di Di Pirro
	WaitForSingleObject(H1dipirro, INFINITE);
	WaitForSingleObject(H2dipirro, INFINITE);
	CloseHandle(H1dipirro);
	CloseHandle(H2dipirro);

	//Di Luigi - End
	WaitForSingleObject(T1_DL, INFINITE);
	WaitForSingleObject(T2_DL, INFINITE);
	CloseHandle(T1_DL); //Liberazione del Thread1
	CloseHandle(T2_DL); //Liberazione del Thread2
	
	WaitForSingleObject(H1Bardazzi, INFINITE);
	WaitForSingleObject(H2Bardazzi, INFINITE);


	WaitForSingleObject(hOrd1, INFINITE);
	WaitForSingleObject(hOrd2, INFINITE);
	CloseHandle(hOrd1);
	CloseHandle(hOrd2);

	WaitForSingleObject(hCompa1, INFINITE);
	WaitForSingleObject(hCompa2, INFINITE);
	CloseHandle(hCompa1);
	CloseHandle(hCompa2);
	
	
	WaitForSingleObject(hBerlincioni1, INFINITE);
	WaitForSingleObject(hBerlincioni2, INFINITE);
	CloseHandle(hBerlincioni1);
	CloseHandle(hBerlincioni2);

	WaitForSingleObject(h1Fiasconi, INFINITE);
	WaitForSingleObject(h2Fiasconi, INFINITE);

	WaitForSingleObject(Pandolfinith1, INFINITE);
	WaitForSingleObject(Pandolfinith2, INFINITE);
	CloseHandle(Pandolfinith1);
	CloseHandle(Pandolfinith2);

	WaitForSingleObject(h1Franchi, INFINITE);
	WaitForSingleObject(h2Franchi, INFINITE);
	CloseHandle(h1Franchi);
	CloseHandle(h2Franchi);


	WaitForSingleObject(hFossati1, INFINITE);
	WaitForSingleObject(hFossati2, INFINITE);
	CloseHandle(hFossati1);
	CloseHandle(hFossati2);

	WaitForSingleObject(hCostanzo1, INFINITE);
	WaitForSingleObject(hCostanzo2, INFINITE);
	CloseHandle(hCostanzo1);
	CloseHandle(hCostanzo2);

	WaitForSingleObject(H1Fantoni, INFINITE);
	WaitForSingleObject(H2Fantoni, INFINITE);
	CloseHandle(H1Fantoni);
	CloseHandle(H2Fantoni);

	WaitForSingleObject(H1Fodde, INFINITE);
	WaitForSingleObject(H2Fodde, INFINITE);
	CloseHandle(H1Fodde);
	CloseHandle(H2Fodde);

	WaitForSingleObject(h1Poneti, INFINITE);
	WaitForSingleObject(h2Poneti, INFINITE);
	CloseHandle(h1Poneti);
	CloseHandle(h2Poneti);


	for (int i = 0; i < 100; i++)
	{
		cout << "iV[" << i << "] = " << iV[i] << "    | iW[" << i << "] = " << iW[i] << endl;

	}

	for (int i = 0; i < 100; i++)
	{
	
		cout << "V1Bardazzi[" << i << "] = " << V1Bardazzi[i] << "    | V2Bardazzi[" << i << "] = " << V2Bardazzi[i] << endl;
	}
	
	//Visualizzazione Vettori Di Pirro
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
	for (int i = 0; i < 100; i++)
	{

		cout << "V1Franchi[" << i << "] = " << V1Franchi[i] << "    | V2Franchi[" << i << "] = " << V2Franchi[i] << endl;
	}

	for (int i = 0; i < 100; i++)
	{
		cout << "iV_Fossati1[" << i << "] = " << iV_Fossati1[i] << "    | iV_Fossati2[" << i << "] = " << iV_Fossati2[i] << endl;
	}
	for (int i = 0; i < 100; i++)
	{
		cout << "iV_Costanzo1[" << i << "] = " << iV_Costanzo1[i] << "    | iV_Costanzo2[" << i << "] = " << iV_Costanzo2[i] << endl;
	}
	for (int i = 0; i < 100; i++)
	{
		cout << "iV_Compa1[" << i << "] = " << iV_Compa1[i] << "    | iV_Compa2[" << i << "] = " << iV_Compa2[i] << endl;
	}

	for (int i = 0; i < 100; i++)
	{

		cout << "V1Fantoni[" << i << "] = " << V1Fantoni[i] << "    | V2Fantoni[" << i << "] = " << V2Fantoni[i] << endl;
	}

	for (int i = 0; i < 100; i++)
	{

		cout << "V1Fodde[" << i << "] = " << V1Fodde[i] << "    | V2Fodde[" << i << "] = " << V2Fodde[i] << endl;
	}

	for (int i = 0; i < 100; i++)
	{
		cout << "iPoneti1[" << i << "] = " << iPoneti1[i] << "    | iPoneti2[" << i << "] = " << iPoneti2[i] << endl;
	}
	system("PAUSE");

	

}
