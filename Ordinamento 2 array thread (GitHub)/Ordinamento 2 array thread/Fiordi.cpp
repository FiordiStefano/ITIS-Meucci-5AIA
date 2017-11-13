/**
Fiordi Stefano
Funzione ordinamento vettori
*/

#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Fiordi.h"
using namespace std;

/**
@fn unsigned __stdcall thOrdina(void * data)
@param data puntatore da passare alla funzione
Funzione che ordina un array di 100 elementi interi in ordine crescente
*/
unsigned __stdcall thOrdFiordi(void * data)
{
	int * iVett = (int *)data;
	for (int i = 100 - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (iVett[j] > iVett[j + 1])
			{
				int iVar = iVett[j];
				iVett[j] = iVett[j + 1];
				iVett[j + 1] = iVar;
			}
		}
	}

	_endthreadex(0); /// termino l'esecuzione del thread
	return(0);
}