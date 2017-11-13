/**
@author BerlincioniMatteo
*/

#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Berlincioni.h"
using namespace std;


unsigned __stdcall Berli(void * data)
{
	int * iV = (int *)data;
	for (int i = 0; i < 9; i++)
	{
		if (iV[i] > iV[i + 1])
		{
				iV[i] = iV[i] + iV[i + 1];
				iV[i + 1] = iV[i] - iV[i + 1];
				iV[i] = iV[i] - iV[i + 1];
		}
	}

	_endthreadex(0); 
	return(0);
}