#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct oe{
	int x;
	struct oe* sljedeci;
}oe;

//generiraj slucajni niz od n elemenata
int * generateArray( int n) {
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		exit(-1);
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	return arr;
}
void printArray(int arr[], int size)
{
	int i;
	printf("Niz: \n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Funkcija za generiranje povezanog popisa iz niza
oe* generateLinkedList(int* array, int size) {
	oe* head = NULL;
	oe* current = NULL;
	for (int i = 0; i < size; i++) {
		oe* newNode = (oe*)malloc(sizeof(oe));
		if (newNode == NULL) {
			printf("Gre�ka prilikom alokacije memorije za �vor povezanog popisa.\n");
			exit(1);
		}
		newNode->x = array[i];
		newNode->sljedeci = NULL;
		if (head == NULL) {
			head = newNode;
			current = newNode;
		}
		else {
			current->sljedeci = newNode;
			current = newNode;
		}
	}
	return head;
}


void printLinkedList(oe* head) {
	printf("Povezani popis: ");
	oe* current = head;
	while (current != NULL) {
		printf(" %d ", current->x);
		current = current->sljedeci;
	}
	printf(" \n");
}


int sequentialSearchArray(int* arr, int n, int num) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == num) {
			return 1;
		}
	}
	return 0;
}

oe* sequentialSearchList(oe* list, int num) {
	while (list != NULL) {
		if (num == list->x)
			return 1;
		list = list->sljedeci;
	}
	return 0;
}

int main() {
	time_t t1, t2;
	int n;
	printf("Unesi broj elemenata niza: \n");
	scanf("%d", &n);

	t1 = clock();
	int* arr = generateArray(n);
	t2 = clock();
	printf("Generiranje random niza: %dms.\n", t2 - t1);

	t1 = clock();
	oe* list = generateLinkedList(arr, n);
	t2 = clock();
	printf("Kreiranje povezane liste: %dms.\n", t2 - t1);


	//printArray(arr, n);
	//printLinkedList(list);

	/*
	int pretraziBroj;
	printf("Unesi broj za pretrazivanje: \n");
	scanf("%d", &pretraziBroj);
	*/

	t1 = clock();
	int arrRez = sequentialSearchArray(arr, n, -1);
	t2 = clock();
	printf("Sekvencijalno pretrazivanje niza: %dms.\n", t2 - t1);
	
	/*if (arrRez)
		printf("Broj je pronaden u nizu.\n");
	else
		printf("Broj nije pronaden u nizu.\n");
	*/

	t1 = clock();
	int listRez = sequentialSearchList(list, -1);
	t2 = clock();
	printf("Sekvencijalno pretrazivanje povezane liste: %dms.\n", t2 - t1);

	
	/*if (listRez)
		printf("Broj je pronaden u listi. \n");
	else
		printf("Broj nije pronaden u listi. \n");
	*/
	free(arr);
	oe* current = list;
	oe* next;
	while (current != NULL) {
		next = current->sljedeci;
		free(current);
		current = next;
	}

	return 0;
}

