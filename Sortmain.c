#include "Sort.h"
#include <stdio.h>
void  PrintArr(int *arr, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}



//插入排序
//当插入第i个元素的时候,前面的arr[0],arr[1],已经排好序
//此时拿出key = arr[i]和arr[i-1],arr[i-2]进行比较(按照我们想要的方式)
//不断进行交换,但是要保存住key这个值
//还要把前一个元素进行记录
//用到了end 这个变量,来记录arr[i]的前一个元素
//所以时间复杂度为O(N^2)
//空间复杂度为O(1)
//是一个稳定的排序
void  InsertSort(int *arr, int size){
	for (int i = 1; i < size; i++){
		int end = i - 1;
		int key = arr[i];
		//改成key <= arr[end],就是非稳定排序了
		while (end >= 0 && key < arr[end]){
			arr[end + 1] = arr[end];
			arr[end--] = key;
		}
	}
}

void  Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
//升序
void BubbleSort(int *arr, int size){
	for (int i = 0; i < size - 1; i++){
		for (int j = 0; j < size - i -1; j++){
			if (arr[j]>arr[j+1]){
				Swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void  MakeHeap(int *arr, int parent, int size){
	int child = 2 * parent + 1;
	while (child < size){
		if (child + 1 < size && arr[child + 1] > arr[child]){
			child = child + 1;
		}
		if (arr[parent] < arr[child]){
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else return;
	}
}


void HeapSort(int *arr, int size){
	//建立堆,建立一个大堆
	for (int root = (size - 2) / 2; root >= 0; root--){
		MakeHeap(arr,root, size);
	}
	//调换收尾
	for (; size >= 1; size--){
		Swap(&arr[0], &arr[size - 1]);
		MakeHeap(arr, 0, size-1);
	}
}
int main(){
	int  arr[] = { 3, 5, 6, 1, 2, 7, 0, 9, 8, 4 };
	/*InsertSort(arr, sizeof(arr) / sizeof(arr[0]));*/
	/*BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));*/
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
