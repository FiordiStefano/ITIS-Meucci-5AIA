#include<process.h>
#include<stdlib.h>
//Funzione che permette l'rdinamento di un vettore
unsigned int _stdcall ordinaC(void* val)
{
	int s;
	int *K = (int*)val;
	for (int y = 0; y<100; y++) {
		for (int i = 0; i < 100 - 1; i++)
		{
			if (K[i] > K[i + 1])
			{
				s = K[i];
				K[i] = K[i + 1];
				K[i + 1] = s;
			}
		}
	}
	_endthread();
	return 0;
}
