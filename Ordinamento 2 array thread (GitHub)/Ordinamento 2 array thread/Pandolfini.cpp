#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Pandolfini.h"
using namespace std;

// Funzione Ordinamento Pandolfini
unsigned int __stdcall ordinamento(void* x)

{
	int *v = (int*)x;

	int c;

	for (int i = 0; i < 100 - 1; i++)

	{
		for (int j = i + 1; j < 100; j++)

		{

			if (v[i] > v[j])

			{
				c = v[i];

				v[i] = v[j];

				v[j] = c;

			}
			else
			{
				break;

			}
		}
	}

	_endthreadex(0);
	return 0;
}
