#pragma once 


typedef int HPDataType;



typedef struct Heap {
	HPDataType* arr;
	int _size;
	int _capacity;

}Heap;

void HeapInit(Heap * hp, HPDataType *arr, int size);
