#include<iostream>
#include<Windows.h>
#include<process.h>
#include"Pandolfini.h"
using namespace std;


unsigned int __stdcall ordinamento(void* x)

{
	int *v = (int*)x;

	int c;

	for (int i = 0; i < 100 - 1; i++)

	{
		for (int j = i + 1; i < 100; j++)

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
	return 0;
}
