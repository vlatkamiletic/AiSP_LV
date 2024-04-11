#define _CRT_SECURE_NO_WARNINGS
#include "SLL.h"
#include <stdlib.h>
#include <stdio.h>

OE* SLLCreate(int x)
{
	OE* newHeadNode = (OE*)malloc(sizeof(OE));
	if (newHeadNode == NULL) {
		exit(-1);
		perror("Error allocating memory for SLL head node.\n");
	}

	newHeadNode->x = x;
	newHeadNode->next = NULL;

	return newHeadNode;
}

OE* SLLAddNode(OE* headNode, int x)
{
	OE* newHeadNode = (OE*)malloc(sizeof(OE));
	if (newHeadNode == NULL) {
		exit(-1);
		perror("Error allocating memory for new SLL node.\n");
	}

	newHeadNode->x = x;
	newHeadNode->next = headNode;

	return newHeadNode;
}

void SLLPrintList(OE* headNode)
{
	OE* traverseNode = headNode;

	while (traverseNode)
	{
		printf("Node address: %p, value: %d\t", traverseNode, traverseNode->x);
		traverseNode = traverseNode->next;
	}
}

OE* SLLSearchSequential(OE* headNode, int x)
{
	OE* traverseNode = headNode;

	while (traverseNode)
	{
		if (traverseNode->x == x) {
			return traverseNode;
		}
		traverseNode = traverseNode->next;
	}
	return NULL;
}

OE* SLLCreateFromArray(int arr[], int size)
{
	OE* headNode = SLLCreate(arr[0]);

	int i;
	for (i = 1; i < size; i++)
	{
		headNode = SLLAddNode(headNode, arr[i]);
	}
	return headNode;
}

