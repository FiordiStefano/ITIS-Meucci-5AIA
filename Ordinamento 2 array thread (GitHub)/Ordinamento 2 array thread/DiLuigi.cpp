/*
Di luigi Marco        V-AIA 13/11/2017
Funzione di ordinamento di due vettori con l' utilizzo di 2 thread
*/

#include"DiLuigi.h"
#include<iostream>
#include<Windows.h>
#include<process.h>

using namespace std;

unsigned Thread_DiLuigi(void * data)
{
	int * V_DL = (int *)data;
	
	for (int i = 100 - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (V_DL[j] > V_DL[j + 1])
			{
				int C = V_DL[j];
				V_DL[j] = V_DL[j + 1];
				V_DL[j + 1] = C;
			}
		}
	}
	_endthread(); //Termino il Thread
}
