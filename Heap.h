#pragma once 


typedef int HPDataType;




typedef struct Heap {
	HPDataType* arr;
	int _size;
	int _capacity;

}Heap;

void HeapInit(Heap * hp, HPDataType *arr, int size);
void HeapDerstory(Heap *hp);
void HeapPush(Heap *hp, HPDataType data);
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int EmptySize(Heap *hp);




void HeapSort(int *arr,int size);