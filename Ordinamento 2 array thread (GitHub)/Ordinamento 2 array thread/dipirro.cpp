/*
Di Pirro Giovanni
ESERCIZIO REPOSITERY REMOTA GITHUB
*/

#include<iostream>
#include<Windows.h>
#include<process.h>
#include"dipirro.h"
using namespace std;


//funzione dell'ordinamento, in modo crescente, di un array di 100 elementi
unsigned __stdcall ord_dipirro(void * d)
{
	int * iV = (int *)d;
	for (int i = 100 - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (iV[j] > iV[j + 1])
			{
				//sposto verso destra il valore più grande, in modo da ordinare tutto l'array in modo crescente alla fine del ciclo
				int x = iV[j];
				iV[j] = iV[j + 1];
				iV[j + 1] = x;
			}
		}
	}
	_endthreadex(0); //termino il thread alla fine dell'ordinamento
	return(0);
}