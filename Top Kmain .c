#include<stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
//1.将集合内前K个元素取出建立一个大堆

//2.建好之后去排序,生成升序序列

//3.排序完成继续导入数据,进行调整

#define MAX   1000
void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AdjustHeap(int *Heap,int parent,int size ){
	int child = 2 * parent + 1;
	while (child < size){
		if (child + 1 < size && Heap[child + 1] > Heap[child]){
			child = child + 1;
		}
		if (Heap[parent] < Heap[child]){

			Swap(&Heap[parent], &Heap[child]);
		}
		parent = child;
		child = 2 * parent + 1;
		
	}
}
void CreatHeap(int *Heap, int size){
	assert(Heap);
	for (int i = size / 2 - 1; i >= 0; i--){	
		AdjustHeap(Heap, i, size);
	}
	for (size; size >= 1; size--){
		Swap(&Heap[0], &Heap[size - 1]);
		AdjustHeap(Heap, 0, size - 1);
	}


}

int main(){

	/*int Heap[10] = { 3, 4, 5, 8, 1, 2, 0, 9, 7, 6 };*/
	int Heap[10];
	int Data[MAX];
	int size = sizeof(Heap) / sizeof(Heap[0]);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++){
		Data[i] = rand();
		}
		for (int i = 0; i < 10; i++){
		Heap[i] = Data[i];
		}
	//创建堆并且排序
	CreatHeap(Heap, size);

	for (int i = 10; i < MAX; i++){
		if (Data[i]>Heap[0]){
			Heap[0] = Data[i];
			CreatHeap(Heap, size);
		}
	}
	for (int i = 0; i < size; i++){
		printf("%d ", Heap[i]);
	}
	return 0;
}