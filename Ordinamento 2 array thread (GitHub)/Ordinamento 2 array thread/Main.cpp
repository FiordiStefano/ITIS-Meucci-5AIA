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

	for (int i = 0; i < 100; i++)
	{
		iV[i] = rand() % 1000 + 1;
		iW[i] = rand() % 1000 + 1;
		V1Bardazzi[i] = rand() % 1000 + 1;
		V2Bardazzi[i] = rand() % 1000 + 1;
		V1dipirro[i] = rand() % 1000 + 1;
		V2dipirro[i] = rand() % 1000 + 1;
	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perché quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non è più possibile chiudere l'handle del relativo thread
	HANDLE hOrd1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE hOrd2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iW, 0, &threadid); /// Lancio del secondo thread

	H1Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V1Bardazzi);
	H2Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V2Bardazzi);
	
	H1dipirro = (HANDLE)_beginthreadex(NULL, 0, &ord_dipirro, V1dipirro, 0,(void*)V1dipirro);
	H2dipirro = (HANDLE)_beginthreadex(NULL, 0, &ord_dipirro, V2dipirro, 0,(void*)V2dipirro);
	
	WaitForSingleObject(H1dipirro, INFINITE);
	WaitForSingleObject(H2dipirro, INFINITE);
	CloseHandle(H1dipirro);
	CloseHandle(H2dipirro);


	WaitForSingleObject(H1Bardazzi, INFINITE);
	WaitForSingleObject(H2Bardazzi, INFINITE);


	WaitForSingleObject(hOrd1, INFINITE);
	WaitForSingleObject(hOrd2, INFINITE);
	CloseHandle(hOrd1);
	CloseHandle(hOrd2);

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

	system("PAUSE");

}