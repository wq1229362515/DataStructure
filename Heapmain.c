#include "Heap.h"
#include <stdio.h>
#include <assert.h>
#include<malloc.h>
void Swap(int *parent,int * child){
	int temp = *parent;
	*parent = *child;
	*child = temp;
}
void AdjustDown(HPDataType *arr, int parent, int size){
	int child = 2 * parent + 1;
	if (arr[child] > arr[parent]){
		return;
	}
	while (child < size){
		if (child+1<size && arr[child]>arr[child + 1]){
			child = child + 1;
		}
		if (arr[parent] > arr[child]){
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		
	}
}
void  HeapInit(Heap *hp, HPDataType *arr, int size){
	assert(hp);
	hp->arr = (HPDataType*)malloc(sizeof(HPDataType)*size);
	hp->_size = 0;
	hp->_capacity = size;
	for (int i = 0; i < size; i++){
		hp->arr[i] = arr[i];
		hp->_size++;
	}
	int parent = 0;
	AdjustDown(hp->arr, parent, size);
	



}
void TestHeap(){
	Heap hp;
	HPDataType arr[] = { 27, 15, 19, 18, 28, 34, 65,49,25,37 };
	int size = (sizeof(arr) / sizeof(arr[0]));
	HeapInit(&hp, arr, size);
}
int main(){

	TestHeap();
	return 0;
}