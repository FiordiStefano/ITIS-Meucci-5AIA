

#include<iostream>
#include<Windows.h>
#include<process.h>
#include<time.h>
#include"Fiordi.h"
#include"Bardazzi.h"
#include"Fodde.h"
using namespace std;

/**
Funzione main del programma nella quale vengono lanciati i thread
*/
void main()
{
	srand(time(NULL));
	int iV[100], iW[100];
	unsigned threadid;
	HANDLE H1Fodde, H2Fodde;
	int V1Fodde[100];
	int V2Fodde[100];

	for (int i = 0; i < 100; i++)
	{
		iV[i] = rand() % 1000 + 1;
		iW[i] = rand() % 1000 + 1;
		V1Fodde[i] = rand() % 1000 + 1;
		V2Fodde[i] = rand() % 1000 + 1;
	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perché quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non è più possibile chiudere l'handle del relativo thread
	HANDLE hOrd1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE hOrd2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iW, 0, &threadid); /// Lancio del secondo thread

	H1Fodde = (HANDLE)_beginthread(Thread, 0, (void*)V1Fodde);
	H2Fodde = (HANDLE)_beginthread(Thread, 0, (void*)V2Fodde);


	WaitForSingleObject(H1Fodde, INFINITE);
	WaitForSingleObject(H2Fodde, INFINITE);


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
	
		cout << "V1Fodde[" << i << "] = " << V1Fodde[i] << "    | V2Fodde[" << i << "] = " << V2Fodde[i] << endl;
	}

	system("PAUSE");

}