#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Poneti.h"
using namespace std;

//Funzione 
unsigned int __stdcall threadPoneti(void *data)
{

	int *V = (int*)data;
	bool cambio;

	do
	{
		cambio = false;


		for (int i = 0; i < 99 - 1; i++)
		{
			if (V[i + 1] < V[i])
			{
				int x = V[i + 1];
				V[i + 1] = V[i];
				V[i] = x;

				cambio = true;
			}
		}

	} while (cambio == true);

	_endthreadex(0);
	return(0);
}