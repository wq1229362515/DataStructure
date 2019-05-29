#include "Sort.h"
#include <stdio.h>
#include <malloc.h>
#include<string.h>
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
			end--;
		}
		arr[end+1] = key;
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

//ϣ������,���ϵ���С���,ȡ���������������
void ShellSort(int *arr, int size){
	int gap = 3;
	while (gap--){
		for (int i = gap; i < size; i++){
			int key = arr[i];
			int end = i - gap;
			while(end >= 0 && arr[end] > key){
				arr[end + gap] = arr[end];
				end  = end - gap;
			}
			arr[end+gap] = key;
		}
	}
}

//ѡ�������ظ��ıȽ�
void ChooseSort(int *arr, int size){
	for (int i = 0; i < size -1 ;i++){
		int Maxpos  = 0;
		for (int j = 1; j < size - i; j++){
			if (arr[j] >arr[Maxpos])Maxpos = j;
		}
		if (arr[size-1-i] != arr[Maxpos]){
			Swap(&arr[size-1-i],&arr[Maxpos]);
		}
	}
}
//˫����,�ȵ�һ�ֵ�������΢��һ��
void ChooseDoubleSort(int *arr, int size){
	int end = size - 1;
	int begin = 0;
	while (begin < end){
		int MaxPos = begin;
		int MinPos = begin;
		int index = begin + 1;
		while (index < end){
			if (arr[MaxPos] < arr[index]) MaxPos = index;
			if (arr[MinPos] > arr[index])MinPos = index;
			index++;
		}
		if (MaxPos != end){
			Swap(&arr[MaxPos], &arr[end]);
		}
		if (MinPos == end){
			MinPos = MaxPos;
		}
		if (MinPos != begin){
			Swap(&arr[MinPos], &arr[begin]);
		}
		begin++;
		end--;
	}
}
//����ȡ�з�ѡȡ����key��ֵ
int GetMiddleIndex(int *arr, int left, int right){
	//�����������бȽ�
	int mid = left + ((right - left) >> 1);
	






	return mid;

}
//hoare ����
//��׼ֵΪ�Ҳ��Ԫ��,���ں���
//��������ָ��
//�������������,����ת�������С�ڻ�׼ֵ,�Ҳ���ڻ�׼ֵ
int Partion1(int *arr, int left, int right){
	int begin = 0;
	int end = right -1;
	int mid = GetMiddleIndex(arr, left, right);
	//����ȡ�з�ȡ��mid,�ٺ�right-1���ұߵĽ�������
	Swap(&arr[mid], &arr[right - 1]);
	int key = arr[right - 1];
	while (begin < end){
		//���ұȻ�׼ֵ���ֵ
		while (begin < end && arr[begin] <= key){
			begin++;
		}
		//�ұȻ�׼ֵС����
		while (begin < end && arr[end] >= key){
			end--;
		}
		if (begin != end){
			Swap(&arr[end], &arr[begin]);
		}
	}
	if (begin != right - 1){
		Swap(&arr[right - 1], &arr[begin]);
	}
	return begin;
}


//��ӷ�,�Ҳ౻��ֵ����key,��˵����������
int Partion2(int *arr, int left, int right){
	int begin = 0;
	int end = right - 1;
	int key = arr[right - 1];
	while (begin < end){
		//��ǰ������
		while (begin < end && arr[begin] <= key){
			begin++;
		}
		//���
		if (begin < end){
			arr[end] = arr[begin];
			end--;
		}
		//�Ӻ���ǰ��
		while (begin < end && arr[end] >= key){
			end--;
		}
		//���
		if (begin < end){
			arr[begin] = arr[end];
			begin--;
		}
	}
	arr[begin] = key;
	return begin;
}
//ָ�뷨,����ָ����һͷ,һǰһ��
int Partion3(int *arr, int left, int right){
	int cur = left;
	int pre = cur - 1;
	int key = arr[right - 1];
	while (cur < right){
		//cur�����Ȼ�׼ֵ���,������
		//����ָ��ֿ��Ļ�pre ����һ��Ԫ��һ���Ȼ�׼ֵ��
		//����Ҫ�ж�����ָ���Ƿ���ͬһ��λ��
		//����ͬһ��λ��,����cur�Ȼ�׼ֵС�Ļ�,����
		//++pre֮����ͬһ��λ�õĻ�ʲôҲ����,�������в��� cur++
		if ((arr[cur] < key) && (++pre != cur)){
			Swap(&arr[cur], &arr[pre]);
		}
		cur++;
	}
		if (++pre != right){
			Swap(&arr[pre], &arr[right - 1]);
		}
	return pre;
}

//ʲô����ȽϺ��ÿ�����,���ֵ������
void _QuickSort(int * arr, int left, int right){
	// �������˵����Ԫ��,��������
	if (right - left > 1){
		//�һ�׼ֵ
		int div = Partion3(arr, left, right);
		//�������
		_QuickSort(arr, left, div);
		//�����ұ�
		_QuickSort(arr, div + 1, right);
	}
}
//��װ��һ��
void QuickSort(int *arr, int size){
	int right = size;
	int left = 0;
	_QuickSort(arr, 0, right);
}
//���ŷǵݹ��õ���ջ
#include "Stack.h"
void QuickSortNor(int *arr, int size){
	int right = size;
	int left = 0;
	Stack s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);
		
	while (!StackEmpty(&s)){
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);
		//���ſ��Ž���,ʣ��һ���Ͳ��û�����
		if (right - left > 1){
			int div = Partion3(arr, left, right);
			//�����Ұ�����
			StackPush(&s, right);
			StackPush(&s, div + 1);
			//�����������
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}
#include <assert.h>
void MergeData(int *arr, int left, int right, int mid,int *temp){
	//[left,mid)
	//[mid,right)
	int begin1 = left; 
	int begin2 = mid;
	int end1 = mid;
	int end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2){
		if (arr[begin1]<arr[begin2]){
			temp[index++] = arr[begin1++];
		}
		else 
			temp[index++] = arr[begin2++];
	}
	while(begin1 < end1){
		temp[index++] = arr[begin1++];
	}
	while (begin2 < end2){
		temp[index++] = arr[begin2++];
	}
}
//��װ��һ��
void _MergeSort(int *arr, int left, int right,int *temp){
	//�Ҳ�������ſ��Խ���,Ҳ����Ҫ�ֳ�һ��һ���Ž��бȽ�
	if (right - left > 1){
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid,temp);
		_MergeSort(arr, mid, right,temp);
		MergeData(arr, left, right, mid,temp);
		memcpy(arr+left,temp+left,sizeof(int)*(right-left));
	}
}

//�鲢Ҫ���пռ�Ŀ���
void MergeSort(int *arr, int size){
	int *temp = (int *)malloc(sizeof(int)*size);
	if (temp == NULL){
		assert(0);
	}
	_MergeSort(arr, 0, size, temp);
	free(temp);
}

//�ǵݹ�ķ���
//ֱ�ӻ��ֳ�n��

//�������鲢
//  gap = 1  ,gap = 2,
void MergeSortNor(int *arr,int size){
	int *temp = (int*)malloc(sizeof(int)*size);
	if (temp == NULL){
		assert(0);
	}
	int gap = 1;
	while (gap < size){
		for (int i = 0; i < size; i += 2 * gap){
			int left = i;
			int mid = left + gap;
			int right = gap + mid;
			
			if (mid >= size){
				mid = size;
			}
			if (right>size){
				right = size;
			}
			MergeData(arr, left, right, mid, temp);
		}
		memcpy(arr, temp, sizeof(int)*size);
		gap = gap * 2;
	}
	free(temp);
}
int main(){
	int  arr[] = { 3, 5, 6, 1, 2, 7, 0, 9, 8, 4 };
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	/*BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));*/
	/*HeapSort(arr, sizeof(arr) / sizeof(arr[0]));*/
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ChooseSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ChooseDoubleSort(arr, sizeof(arr)/ sizeof(arr[0]));
	//QuickSort(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSortNor(arr, sizeof(arr) / sizeof(arr[0]));
	//MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	MergeSortNor(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
