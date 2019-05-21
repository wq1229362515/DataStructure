#include "Heap.h"
#include <stdio.h>
#include <assert.h>
#include<malloc.h>
#include <stdlib.h>
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
	int parent = 0;	//传入根节点
	AdjustDown(hp->arr, parent, size);
}
void HeapDerstory(Heap *hp){
	assert(hp);
	free(hp->arr);
	hp->arr = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
void CheckCapacity(Heap *hp){
	if (hp->_capacity == hp->_size){
		int NewCapactiy = 2 * hp->_capacity;
		HPDataType *temp = (HPDataType*)malloc(sizeof(HPDataType));
		for (int i = 0; i < hp->_size; i++){
			temp[i] = hp->arr[i];
		}
		hp->_capacity = NewCapactiy;
		hp->arr = temp;
	}
}
//从下往上比较遍历
void HeapPush(Heap *hp, HPDataType data){
	int child = hp->_size;                               //创建子节点
	int parent =(child - 1)/2;
	assert(hp);
	CheckCapacity(hp);
	hp->arr[hp->_size] = data;
	while (child){
		if (hp->arr[child] >= hp->arr[parent]){
			hp->_size++;
			return;
		}
		else {
			Swap(&hp->arr[child], &hp->arr[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
	}
	hp->_size++;
}
void HeapPop(Heap *hp){
	assert(hp);
	hp->arr[0] = hp->arr[hp->_size-1];
	hp->_size--;
	AdjustDown(hp->arr, 0, hp->_size);
	/*system("pause");*/
}
HPDataType HeapTop(Heap *hp){
	return hp->arr[0];
}
int HeapSize(Heap *hp){
	return hp->_size;
}
int EmptySize(Heap *hp){
	return 0 == hp->_size;
}
void  HeapAdjust(int *arr, int parent, int size){
	int child = 2 * parent + 1;
	while (child < size){
		if (child + 1 < size&&arr[child + 1] > arr[child]){
			child = child + 1;
		}
		if (arr[child]>arr[parent]){
			Swap(&arr[child], &arr[parent]);
		}
		parent = child;
		child = 2 * parent + 1;
	}
}
void HeapMake(int *arr,int size){
	for (int i = size / 2 - 1; i >= 0; i--){
		HeapAdjust(arr,i,size);
	}
}


void HeapSort(int *arr, int size){
	assert(arr);
	//调整成大堆序	
	HeapMake(arr,size);
	//调换位置排序
	for (size; size >= 1;size--){
		//最大的和最后一个数字调换
		Swap(&arr[0], &arr[size-1]);
		//从上开始调整,因为已经排成了我们要求的堆序
		HeapAdjust(arr, 0, size - 1);
	}
	//system("pause");
}
void TestHeap(){
	Heap hp;
	HPDataType arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = (sizeof(arr) / sizeof(arr[0]));
	HeapInit(&hp, arr, size);
	HeapPop(&hp);
	HeapPush(&hp, 12);
	HeapPush(&hp, 10);
}

void TestHeap2(){
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}
int main(){

	/*TestHeap();*/
	TestHeap2();
	return 0;
}