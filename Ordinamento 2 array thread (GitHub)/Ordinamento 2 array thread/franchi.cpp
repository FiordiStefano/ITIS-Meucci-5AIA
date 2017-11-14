/**
@author Franchi Federico
@date 14/11/2017
questo file contiene la funzione che esegue l'ordinamenre del vettore 
contenuto nel main
*/
#include<process.h>
#include<stdio.h>
#include"franchi.h"
using namespace std;

/**
questa è la funzione che esegue l'odinamento dei vettori
@param val : vriabil puntatore che punta al mio vettore
*/
unsigned  _stdcall ordinafranchi(void* val)
{
	int s;
	int* v =(int*)val;
	//int n = sizeof(*v) / sizeof(int);
	/**fase di controllo del vettore passato (ovvero del vettore puntato dalla variabile che ci è stata passata)*/
	for (int y = 0; y < 100; y++)
	{
		for (int i = 0; i < 100 - 1; i++)
		{
			if (v[i] > v[i + 1])
			{
				 s = v[i];
				v[i] = v[i + 1];
				v[i + 1] = s;
			}
		}
	}
	_endthreadex(0);
	//return 0;
}