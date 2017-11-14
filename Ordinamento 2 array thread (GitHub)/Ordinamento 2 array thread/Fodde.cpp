/*Esercitazione tpsit
Fodde Rebecca*/
#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Fodde.h"
using namespace std;

//funzione che ordina il vettore in ordine crescente
unsigned _stdcall FoddeF(void *data)
{
	int *V = (int*)data; //passa il vettore
	bool cambio;

	do
	{
		cambio = false;


		for (int i = 0; i < 99 ; i++) //scorre il vettore
		{
			//controlla se la casella successiva è maggiore della prima e nel caso la ordina
			if (V[i + 1] < V[i]) 
			{
				int x = V[i + 1];
				V[i + 1] = V[i];
				V[i] = x;

				cambio = true;
			}
		}

	} while (cambio == true);

	_endthreadex(0); //fa terminare il thread
	return 0;
}