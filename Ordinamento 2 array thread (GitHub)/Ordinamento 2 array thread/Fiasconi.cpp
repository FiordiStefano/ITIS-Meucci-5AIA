/**
Fiasconi Loris
*/

#include<iostream>
#include<Windows.h>
#include<process.h>
#include<Fiasconi.h>
using namespace std;

void Ordina(void* data)
{

	int* V = (int*)data;

	int i = 0;
	int tmp = 0;
	int j = 0;

	for (i = 0;i < 100 - 1;i++)
	{
		for (j = i + 1;j < 100;j++)
		{
			if (V[i] > V[j])
			{
				tmp = V[i];
				V[i] = V[j];
				V[j] = tmp;
			}
		}
	}
}