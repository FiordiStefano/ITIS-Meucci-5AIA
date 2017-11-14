/**
Fiasconi Loris
*/

#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Fiasconi.h"
using namespace std;

void Ordina(void* data)
{
    //inizializzo variabile V
	int* V = (int*)data;

	int i = 0;
	int tmp = 0;
	int j = 0;

    //primo ciclo for 
	for (i = 0;i < 100 - 1;i++)
	{
        //seondo ciclo for
		for (j = i + 1;j < 100;j++)
		{
			if (V[i] > V[j]) //condizione: se il valore del numero del primo ciclo e' maggiore del secondo allora ->
			{
				tmp = V[i]; //assegno alla variabile tmp il valore del numero del primo ciclo
				V[i] = V[j]; //assegno al valore del numero del primo ciclo il valore del secondo 
				V[j] = tmp; //assegno al valore del secondo ciclo il valore del primo (tramite variabile tmp)
			}
		}
	}
}
