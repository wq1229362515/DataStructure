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