#include <iostream>
#include<process.h>
#include<Windows.h>
#include"Bardazzi.h"

using namespace std;

void Thread(void *data)
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

}