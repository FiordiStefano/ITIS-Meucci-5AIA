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
#include"Fossati.h"
using namespace std;

/**
Funzione main del programma nella quale vengono lanciati i thread
*/
void main()
{
	srand(time(NULL));
	int iV[100], iW[100];
	unsigned threadid;
	HANDLE H1Bardazzi, H2Bardazzi;
	int V1Bardazzi[100];
	int V2Bardazzi[100];
	int V1Fossati[100];
	int V2Fossati[100];
	for (int i = 0; i < 100; i++)
	{
		iV[i] = rand() % 1000 + 1;
		iW[i] = rand() % 1000 + 1;
		V1Bardazzi[i] = rand() % 1000 + 1;
		V2Bardazzi[i] = rand() % 1000 + 1;
		V1Fossati[i] = rand() % 1000 + 1;
		V2Fossati[i] = rand() % 1000 + 1;
	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perch� quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non � pi� possibile chiudere l'handle del relativo thread
	HANDLE hOrd1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE hOrd2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iW, 0, &threadid); /// Lancio del secondo thread
	H1Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V1Bardazzi);
	H2Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V2Bardazzi);
	HANDLE H1Fossati = (HANDLE)_beginthreadex(NULL, 0, &FossatiOrd, V1Fossati, 0,(void*)V1Fossati); 
	HANDLE H2Fossati = (HANDLE)_beginthreadex(NULL, 0, &FossatiOrd, V2Fossati, 0, (void*)V2Fossati);

	WaitForSingleObject(H1Bardazzi, INFINITE);
	WaitForSingleObject(H2Bardazzi, INFINITE);


	WaitForSingleObject(H1Fossati, INFINITE);
	WaitForSingleObject(H2Fossati, INFINITE);
	CloseHandle(H1Fossati);
	CloseHandle(H2Fossati);


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

	cout << "Vettori Ordinati Fossati\n";
	for (int i = 0; i < 100; i++)
	{

		cout << "V1Fossati[" << i << "] = " << V1Fossati[i] << "    | V2Fossati[" << i << "] = " << V2Fossati[i] << endl;
	}
	system("PAUSE");

}