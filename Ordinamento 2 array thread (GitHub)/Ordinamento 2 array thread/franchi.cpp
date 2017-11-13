#include<process.h>
#include<stdio.h>

unsigned  _stdcall ordina(void* val)
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
	_endthread();
	return 0;
}