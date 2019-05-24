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

int main(){
	int  arr[] = { 3, 5, 6, 1, 2, 7, 0, 9, 8, 4 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
