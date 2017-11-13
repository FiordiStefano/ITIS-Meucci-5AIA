

#include<iostream>
#include<Windows.h>
#include<process.h>
#include<time.h>
#include"Fantoni.h"


using namespace std;

/**
Funzione main del programma nella quale vengono lanciati i thread
*/
void main()
{
	srand(time(NULL));
	int iV[100], iW[100];

	unsigned threadid;

	for (int i = 0; i < 100; i++)
	{
		iV[i] = rand() % 1000 + 1;
		iW[i] = rand() % 1000 + 1;
	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perché quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non è più possibile chiudere l'handle del relativo thread

	
	HANDLE Fantoni1 = (HANDLE)_beginthreadex(NULL, 0, &FantoniF, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE Fantoni2 = (HANDLE)_beginthreadex(NULL, 0, &FantoniF, iW, 0, &threadid); /// Lancio del secondo thread


	WaitForSingleObject(Fantoni1, INFINITE);
	WaitForSingleObject(Fantoni2, INFINITE);

	
	CloseHandle(Fantoni1);
	CloseHandle(Fantoni2);

	for (int i = 0; i < 100; i++)
	{
		cout << "iV[" << i << "] = " << iV[i] << "    | iW[" << i << "] = " << iW[i] << endl;
	}

	system("PAUSE");

}