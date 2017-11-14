/**
@author Riccardo Fossati
Funzione per l'ordinamento di un vettore
*/

#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Fossati.h"
using namespace std;

/**
Funzione che permette l'ordinamento degli elementi di un vettore in ordine crescente.
*/
unsigned __stdcall FossatiOrd(void * data)
{
	int *V = (int*)data;
	int x;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100 - i; j++)
		{
			if (V[j] > V[j + 1])
			{
				x = V[j];
				V[j] = V[j + 1];
				V[j + 1] = x;
			}
		}
	}
	_endthreadex(0); 
	return(0);
}