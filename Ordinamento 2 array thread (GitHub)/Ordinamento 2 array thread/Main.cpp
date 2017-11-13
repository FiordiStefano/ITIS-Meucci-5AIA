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
<<<<<<< HEAD
#include"franchi.h"
=======
#include"Bardazzi.h"
<<<<<<< HEAD
#include"DiLuigi.h" 

=======
#include"Fossati.h"
#include"dipirro.h"
>>>>>>> 4cc6699e57cb010f8743a7d5556cee4a21c3fbff
>>>>>>> c06b4ee2c22b5b6de9226f59a3057e3f93dee51f
using namespace std;

/**
Funzione main del programma nella quale vengono lanciati i thread
*/
void main()
{
	srand(time(NULL));
	int iV[100], iW[100];
	unsigned threadid;
<<<<<<< HEAD

=======
	HANDLE H1Bardazzi, H2Bardazzi;
	int V1Bardazzi[100];
	int V2Bardazzi[100];
<<<<<<< HEAD
	
	//Var Di Luigi
	int V1_DiLuigi[100];
	int V2_DiLuigi[100];
	HANDLE T1_DL, T2_DL;
	
	//Var Di Pirro
	int V1dipirro[100];
	int V2dipirro[100];
	HANDLE H1dipirro, H2dipirro;
	
	
=======
	int V1Fossati[100];
	int V2Fossati[100];
>>>>>>> 4cc6699e57cb010f8743a7d5556cee4a21c3fbff
>>>>>>> c06b4ee2c22b5b6de9226f59a3057e3f93dee51f
	for (int i = 0; i < 100; i++)
	{
		iV[i] = rand() % 1000 + 1;
		iW[i] = rand() % 1000 + 1;
<<<<<<< HEAD
=======
		V1Bardazzi[i] = rand() % 1000 + 1;
		V2Bardazzi[i] = rand() % 1000 + 1;
<<<<<<< HEAD
		V1_DiLuigi[i] = rand() % 1000 + 1:
		V2_DiLuigi[i] = rand() % 1000 + 1;
=======
		V1Fossati[i] = rand() % 1000 + 1;
		V2Fossati[i] = rand() % 1000 + 1;
		V1dipirro[i] = rand() % 1000 + 1;
		V2dipirro[i] = rand() % 1000 + 1;
>>>>>>> 4cc6699e57cb010f8743a7d5556cee4a21c3fbff
>>>>>>> c06b4ee2c22b5b6de9226f59a3057e3f93dee51f
	}

	/// Per lanciare i thread uso _beginthreadex, e non _beginthread, perché quest'ultimo quando l'esecuzione del thread
	/// viene terminata velocemente, la funzione si comporta in modo anomalo, e non è più possibile chiudere l'handle del relativo thread
	HANDLE hOrd1 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iV, 0, &threadid); /// Lancio del primo thred
	HANDLE hOrd2 = (HANDLE)_beginthreadex(NULL, 0, &thOrdFiordi, iW, 0, &threadid); /// Lancio del secondo thread
<<<<<<< HEAD
	HANDLE h1Franchi = (HANDLE)_beginthreadex(NULL, 0, ordina, iV, 0, &threadid);
	HANDLE h2Franchi = (HANDLE)_beginthreadex(NULL, 0, ordina, iW, 0, &threadid);
	WaitForSingleObject(h1Franchi, INFINITE);
	WaitForSingleObject(h2Franchi, INFINITE);
	CloseHandle(h1Franchi);
	CloseHandle(h2Franchi);
=======
	H1Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V1Bardazzi);
	H2Bardazzi = (HANDLE)_beginthread(Thread, 0, (void*)V2Bardazzi);
<<<<<<< HEAD

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
=======
	HANDLE H1Fossati = (HANDLE)_beginthreadex(NULL, 0, &FossatiOrd, V1Fossati, 0,(void*)V1Fossati); 
	HANDLE H2Fossati = (HANDLE)_beginthreadex(NULL, 0, &FossatiOrd, V2Fossati, 0, (void*)V2Fossati);

	WaitForSingleObject(H1Bardazzi, INFINITE);
	WaitForSingleObject(H2Bardazzi, INFINITE);


	WaitForSingleObject(H1Fossati, INFINITE);
	WaitForSingleObject(H2Fossati, INFINITE);
	CloseHandle(H1Fossati);
	CloseHandle(H2Fossati);
	
	H1dipirro = (HANDLE)_beginthreadex(NULL, 0, &ord_dipirro, V1dipirro, 0,(void*)V1dipirro);
	H2dipirro = (HANDLE)_beginthreadex(NULL, 0, &ord_dipirro, V2dipirro, 0,(void*)V2dipirro);
	WaitForSingleObject(H1dipirro, INFINITE);
	WaitForSingleObject(H2dipirro, INFINITE);
	CloseHandle(H1dipirro);
	CloseHandle(H2dipirro);

	

>>>>>>> 4cc6699e57cb010f8743a7d5556cee4a21c3fbff
	WaitForSingleObject(hOrd1, INFINITE);
	WaitForSingleObject(hOrd2, INFINITE);
    CloseHandle(hOrd1);
>>>>>>> c06b4ee2c22b5b6de9226f59a3057e3f93dee51f
	CloseHandle(hOrd2);
	
	//Di Luigi - End
	CloseHandle(T1_DL);
	CloseHandle(T2_DL);
	

	for (int i = 0; i < 100; i++)
	{
		cout << "iV[" << i << "] = " << iV[i] << "    | iW[" << i << "] = " << iW[i] << endl;
	}

	cout << "Vettori Ordinati Fossati\n";
	for (int i = 0; i < 100; i++)
	{

<<<<<<< HEAD
	//Di Luigi - Vid
	for (int i = 0; i < 100; i++)
	{	
		cout << "V1_DiLuigi [" << i << "] = " << V1_DiLuigi[i] << "    | V2_DiLuigi [" << i << "] = " << V2_DiLuigi[i] << endl;
	}
	
=======
		cout << "V1Fossati[" << i << "] = " << V1Fossati[i] << "    | V2Fossati[" << i << "] = " << V2Fossati[i] << endl;
	}
	for (int i = 0; i < 100; i++)
	{
	
		cout << "V1-DiPirro[" << i << "] = " << V1dipirro[i] << "    | V2-DiPirro[" << i << "] = " << V2dipirro[i] << endl;
	}
>>>>>>> c06b4ee2c22b5b6de9226f59a3057e3f93dee51f
	system("PAUSE");

}
