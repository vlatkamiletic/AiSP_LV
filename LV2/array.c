#define _crt_secure_no_warnings
#include <stdlib.h>
#include <time.h>
#include "array.h"

int* arraygeneraterandom(int size, int dg, int gg)
{
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr == null) {
		exit(-1);
	}

	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = dg + (float)rand() / rand_max * (gg - dg);
	}

	return arr;
}

int arraysearchsequential(int* arr, int size, int x)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

void arrayprint(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}