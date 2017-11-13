#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Costanzo.h"
using namespace std;


unsigned __stdcall thOrdCostanzo(void * data)
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

	_endthreadex(0); 
	return(0);
}