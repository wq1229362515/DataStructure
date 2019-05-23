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
		else {
			return;
		}
	}
}

//插入用的是向上调整
//建立在已经建立堆的前提下
void AdjustUp(HPDataType *arr, int child, int size){
	int parent = (child - 1) / 2;
	while (child){
		if (arr[parent] > arr[child]){
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else return;
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
	//向下调整法
	int root = (size - 2) / 2;
	for (; root >= 0; root--){
		AdjustDown(hp->arr,root, size);
	}
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

void HeapPush(Heap *hp, HPDataType data){
	CheckCapacity(hp);
	hp->arr[hp->_size] = data;
	hp->_size++;
	AdjustUp(hp->arr, hp->_size-1,hp->_size);

}
void HeapPop(Heap *hp){
	if (EmptySize(hp)){
		return;
	}
	Swap(&hp->arr[0], &hp->arr[hp->_size - 1]);
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
	//比较左右两个孩子
	while (child < size){
		if (child + 1 < size&&arr[child + 1] > arr[child]){
			child = child + 1;
		}
		//和父节点比较,如果大于那么交换,再次向下比较,如果小于说明这个堆是一个大堆
		//返回执行下一个
		if (arr[child]>arr[parent]){
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else return;
	}
}
void HeapMake(int *arr,int size){
	//传进去的是下标,依次倒着调整最后一个非叶子节点
	for (int root = (size -2)/ 2 ; root >= 0; root--){
		HeapAdjust(arr,root,size);
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
		//size的长度要减一
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
	TestHeap();
	/*TestHeap2();*/
	return 0;
}