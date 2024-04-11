#pragma once

typedef struct OE_ {
	int x;
	struct OE_* next;
}OE;

OE* SLLCreate(int x);
OE* SLLAddNode(OE* headNode, int x);
void SLLPrintList(OE* headNode);
OE* SLLSearchSequential(OE* headNode, int x);
OE* SLLCreateFromArray(int arr[], int size);

//Implementirati za DZ
void SLLDeleteNode(OE** headNode, OE* target);
OE* SLLDeleteList(OE* headNode);
void SLLPrintNode(OE* node);
OE* SLLReverseList(OE* node);
void SLLInsertNode(OE* prevNode, int x);