/**
@author Fiordi Stefano - Di Luigi Marco
@date 21/09/2017
Ordinamento di due vettori dichiarati nel main con 2 thread utilizzando un'unica funzione
*/

#include<iostream>
#include<Windows.h>
#include<process.h>
#include<time.h>
#include"Fiordi.h"
#include"Bardazzi.h"
#include"DiLuigi.h" 

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
		V1_DiLuigi[i] = rand() % 1000 + 1:
		V2_DiLuigi[i] = rand() % 1000 + 1;
	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perch� quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non � pi� possibile chiudere l'handle del relativo thread
	HANDLE hOrd1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE hOrd2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iW, 0, &threadid); /// Lancio del secondo thread

	H1Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V1Bardazzi);
	H2Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V2Bardazzi);

	//Di Luigi - Start
	T1_DL = (HANDLE)_beginthread(Thread_DiLuigi, 0, (void*)V1_DiLuigi);
	T2_DL = (HANDLE)_beginthread(Thread_DiLuigi, 0, (void*)V2_DiLuigi);		
			
	WaitForSingleObject(H1Bardazzi, INFINITE);
	WaitForSingleObject(H2Bardazzi, INFINITE);
	
	WaitForSingleObject(hOrd1, INFINITE);
	WaitForSingleObject(hOrd2, INFINITE);
	
	WaitForSingleObject(T1_DL, INFINITE);
	WaitForSingleObject(T2_DL, INFINITE);
	
	CloseHandle(hOrd1);
	CloseHandle(hOrd2);
	
	//Di Luigi - End
	CloseHandle(T1_DL);
	CloseHandle(T2_DL);
	

	for (int i = 0; i < 100; i++)
	{
		cout << "iV[" << i << "] = " << iV[i] << "    | iW[" << i << "] = " << iW[i] << endl;

	}

	for (int i = 0; i < 100; i++)
	{
	
		cout << "V1Bardazzi[" << i << "] = " << V1Bardazzi[i] << "    | V2Bardazzi[" << i << "] = " << V2Bardazzi[i] << endl;
	}

	//Di Luigi - Vid
	for (int i = 0; i < 100; i++)
	{	
		cout << "V1_DiLuigi [" << i << "] = " << V1_DiLuigi[i] << "    | V2_DiLuigi [" << i << "] = " << V2_DiLuigi[i] << endl;
	}
	
	system("PAUSE");

}
