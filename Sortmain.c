#include "Sort.h"
#include <stdio.h>
void  PrintArr(int *arr, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}



//��������
//�������i��Ԫ�ص�ʱ��,ǰ���arr[0],arr[1],�Ѿ��ź���
//��ʱ�ó�key = arr[i]��arr[i-1],arr[i-2]���бȽ�(����������Ҫ�ķ�ʽ)
//���Ͻ��н���,����Ҫ����סkey���ֵ
//��Ҫ��ǰһ��Ԫ�ؽ��м�¼
//�õ���end �������,����¼arr[i]��ǰһ��Ԫ��
//����ʱ�临�Ӷ�ΪO(N^2)
//�ռ临�Ӷ�ΪO(1)
//��һ���ȶ�������
void  InsertSort(int *arr, int size){
	for (int i = 1; i < size; i++){
		int end = i - 1;
		int key = arr[i];
		//�ĳ�key <= arr[end],���Ƿ��ȶ�������
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
//����
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
	//������,����һ�����
	for (int root = (size - 2) / 2; root >= 0; root--){
		MakeHeap(arr,root, size);
	}
	//������β
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
