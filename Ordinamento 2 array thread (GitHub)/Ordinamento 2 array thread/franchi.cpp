#include<process.h>
#include<stdio.h>
#include"franchi.h"
using namespace std;

unsigned  _stdcall ordinafranchi(void* val)
{
	int s;
	int* v =(int*)val;
	//int n = sizeof(*v) / sizeof(int);
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
	return 0;
}