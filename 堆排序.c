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
	//�����ɴ����	
	HeapMake(arr,size);
	//����λ������
	for (size; size >= 1;size--){
		//���ĺ����һ�����ֵ���
		Swap(&arr[0], &arr[size-1]);
		//���Ͽ�ʼ����,��Ϊ�Ѿ��ų�������Ҫ��Ķ���
		HeapAdjust(arr, 0, size - 1);
	}
	//system("pause");
}