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

//希尔排序,不断的缩小间隔,取到近似有序的序列
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

//选择排序重复的比较
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
//双向排,比第一种单向能稍微好一点
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
//三树取中法选取索引key的值
int GetMiddleIndex(int *arr, int left, int right){
	//三数两两进行比较
	int mid = left + ((right - left) >> 1);
	






	return mid;

}
//hoare 方法
//基准值为右侧的元素,便于好找
//定义两个指针
//将不规则的数组,慢慢转换成左侧小于基准值,右侧大于基准值
int Partion1(int *arr, int left, int right){
	int begin = 0;
	int end = right -1;
	int mid = GetMiddleIndex(arr, left, right);
	//三数取中法取出mid,再和right-1最右边的交换即可
	Swap(&arr[mid], &arr[right - 1]);
	int key = arr[right - 1];
	while (begin < end){
		//先找比基准值大的值
		while (begin < end && arr[begin] <= key){
			begin++;
		}
		//找比基准值小的数
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


//填坑法,右侧被赋值给了key,就说明被挖走了
int Partion2(int *arr, int left, int right){
	int begin = 0;
	int end = right - 1;
	int key = arr[right - 1];
	while (begin < end){
		//从前往后找
		while (begin < end && arr[begin] <= key){
			begin++;
		}
		//填坑
		if (begin < end){
			arr[end] = arr[begin];
			end--;
		}
		//从后往前找
		while (begin < end && arr[end] >= key){
			end--;
		}
		//填坑
		if (begin < end){
			arr[begin] = arr[end];
			begin--;
		}
	}
	arr[begin] = key;
	return begin;
}
//指针法,两个指针在一头,一前一后
int Partion3(int *arr, int left, int right){
	int cur = left;
	int pre = cur - 1;
	int key = arr[right - 1];
	while (cur < right){
		//cur遇到比基准值大的,就跳过
		//两个指针分开的话pre 的下一个元素一定比基准值大
		//还需要判断两个指针是否在同一个位置
		//不在同一个位置,并且cur比基准值小的话,交换
		//++pre之后再同一个位置的话什么也不干,继续进行操作 cur++
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

//什么情况比较好用快排序,均分的情况下
void _QuickSort(int * arr, int left, int right){
	// 如果大于说明有元素,进行排序
	if (right - left > 1){
		//找基准值
		int div = Partion3(arr, left, right);
		//排序左边
		_QuickSort(arr, left, div);
		//排序右边
		_QuickSort(arr, div + 1, right);
	}
}
//封装了一层
void QuickSort(int *arr, int size){
	int right = size;
	int left = 0;
	_QuickSort(arr, 0, right);
}
//快排非递归用到了栈
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
		//随着快排进行,剩余一个就不用划分了
		if (right - left > 1){
			int div = Partion3(arr, left, right);
			//保存右半区间
			StackPush(&s, right);
			StackPush(&s, div + 1);
			//保存左半区间
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
//封装的一层
void _MergeSort(int *arr, int left, int right,int *temp){
	//右侧大于左侧才可以进入,也就是要分成一个一个才进行比较
	if (right - left > 1){
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid,temp);
		_MergeSort(arr, mid, right,temp);
		MergeData(arr, left, right, mid,temp);
		memcpy(arr+left,temp+left,sizeof(int)*(right-left));
	}
}

//归并要进行空间的开拓
void MergeSort(int *arr, int size){
	int *temp = (int *)malloc(sizeof(int)*size);
	if (temp == NULL){
		assert(0);
	}
	_MergeSort(arr, 0, size, temp);
	free(temp);
}

//非递归的方法
//直接划分成n组

//再两两归并
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
