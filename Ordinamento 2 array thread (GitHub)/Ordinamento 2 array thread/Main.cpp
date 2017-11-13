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
#include"Costanzo.h"
using namespace std;

/**
Funzione main del programma nella quale vengono lanciati i thread
*/
void main()
{
	srand(time(NULL));
	int iV[100], iW[100],iC[100],iS[100];
	unsigned threadid;

	for (int i = 0; i < 100; i++)
	{
		iV[i] = rand() % 1000 + 1;
		iW[i] = rand() % 1000 + 1;
		iC[i] = rand() % 1000 + 1;
		iS[i] = rand() % 1000 + 1;
	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perché quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non è più possibile chiudere l'handle del relativo thread
	HANDLE hOrd1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE hOrd2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iW, 0, &threadid); /// Lancio del secondo thread
	HANDLE hOrdCostanzo1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdCostanzo, iC, 0, &threadid); 
	HANDLE hOrdCostanzo2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdCostanzo, iS, 0, &threadid);
	WaitForSingleObject(hOrd1, INFINITE);
	WaitForSingleObject(hOrd2, INFINITE);
	WaitForSingleObject(hOrdCostanzo1, INFINITE);
	WaitForSingleObject(hOrdCostanzo2, INFINITE);
	CloseHandle(hOrd1);
	CloseHandle(hOrd2);
	CloseHandle(hOrdCostanzo1);
	CloseHandle(hOrdCostanzo2);

	for (int i = 0; i < 100; i++)
	{
		cout << "iV[" << i << "] = " << iV[i] << "    | iW[" << i << "] = " << iW[i] << endl;
		cout << "iC[" << i << "] = " << iC[i] << "    | iS[" << i << "] = " << iS[i] << endl;

	}

	system("PAUSE");

}