#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Fantoni.h"
using namespace std;

//Funzione utilizzata per ordinare il vettore in ordine crescente 

unsigned _stdcall FantoniF(void *data)
{
	int *V = (int*)data;
	bool cambio;

	do
	{
		cambio = false;


		for (int i = 0; i < 99 ; i++) //Scorre il vettore 
		{
			if (V[i + 1] < V[i]) // Controlla se la casella successiva del vettore è maggiore della casella corrente 
			{
				int x = V[i + 1];
				V[i + 1] = V[i];
				V[i] = x;

				cambio = true;
			}
		}

	} while (cambio == true);

	_endthreadex(0); //Termina il Thread
	return 0;
}