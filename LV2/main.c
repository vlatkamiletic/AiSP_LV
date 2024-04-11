#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array.h"
#include "SLL.h"

void Task1();


int main() {
	srand((unsigned)time(NULL));
	Task1();
	return 0;
}

void Task1()
{
	int n;
	printf("unesite velicinu niza N:\n");
	scanf("%d", &n);

	int* V = NULL;
	OE* SLLHead = NULL;
	time_t t1, t2;

	t1 = clock();
	V = ArrayGenerateRandom(n, 0, 100);
	t2 = clock();
	printf("Generating a random array took %dms.\n", t2 - t1);

	t1 = clock();
	SLLHead = SLLCreateFromArray(V, n);
	t2 = clock();
	printf("Creating a linked list  took %dms.\n", t2 - t1);

	t1 = clock();
	int arrayResult = ArraySearchSequential(V, n, -1);
	t2 = clock();
	printf("Sequentially searching  took %dms \n", t2 - t1);

	t1 = clock();
	OE* listResult = SLLSearchSequential(SLLHead, -1);
	t2 = clock();
	printf("Sequentially searching a linked list took %dms \n", t2 - t1);
}
