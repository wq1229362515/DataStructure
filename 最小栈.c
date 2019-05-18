typedef int SDataType;

typedef struct Stack {
	SDataType *arr;
	int top;
	int capacity;
}Stack;



void StackInit(Stack *ps );
void StackPush (Stack *ps,SDataType data);
void StackPop(Stack *ps);
SDataType StackTop(Stack *ps);
int StackEmpty(Stack *ps);
void StackDestroy(Stack *ps);
int  StackSize(Stack *ps);


void StackInit(Stack *ps ){	
	assert(ps);
	ps->arr = (SDataType*)malloc (sizeof(SDataType)*5);
	if(ps->arr ==NULL){
		assert(0);
		return;
	}
	ps->capacity = 5;
	ps->top = 0;
}
void StackPush (Stack *ps,SDataType data){
	assert(ps);
	if(ps->top == ps->capacity){
		int Newcapacity = 2*ps->capacity;
		int i;
		SDataType *NewStack;
		NewStack = (SDataType *)malloc(sizeof(SDataType)*Newcapacity);
		for(i = 0;i<ps->top;i++){
			NewStack[i] = ps->arr[i];
		}
		free(ps->arr);
		ps->arr = NewStack;
		ps->capacity = Newcapacity;
	}		

	ps->arr[ps->top] = data;	
	ps->top++;
}
void StackPop(Stack *ps){
	assert(ps);
	if(StackEmpty (ps)){
		return ;
	}
	ps->top--;

}
SDataType StackTop(Stack *ps) {
	assert(ps);
	return ps->arr[ps->top-1];
}
int StackEmpty(Stack *ps){
	assert(ps);
	return 0 == ps->top;
}
int StackSize(Stack *ps){
	assert(ps);
	return ps->top;
}
void StackDestroy(Stack *ps) {
	assert(ps);
	if(ps->arr){
		free(ps->arr);
		ps->top = 0;
		ps->capacity = 0;
	}
}


//ջ�ǲ��ܱ�����,û�б����Ĳ���
//push o(1)
//pop  o(1)
//top  o(1)
//getmin o(1)


//һ�ο��Դ�ջ���������Ԫ��
//��һ��Ԫ�ش�����Сֵ
//�ڶ���Ԫ�ش�������
//ջ��Ԫ�� ��ȡtop������ 
//��ջһ�γ�����


//����ջ , s1��������  ,s2 ������Сֵ
/*
��ջ :
    s1 ÿ�ζ���Ҫ��һ��Ԫ��
    s2 data<=��Сֵ
    s2 ҲҪ��Ԫ��
��ջ:
    s1 ÿ�ζ���Ҫ��һ��Ԫ��
    s2 ��ȵ��������������
    �����ʱ��s1 ��һ��Ԫ��
*/


typedef struct {
    Stack ds;
    Stack ms;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    //MinStack obj  ��ʱ�����ں������ڵ�ջ����, ����������ͷ�����
    //��һ����ʱ����,�������н���,���������������
    //ͨ��malloc�ŵ�������ȥ
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    if(obj == NULL) {
        assert(obj);
        return NULL;
    }
    StackInit(&obj->ds);
    StackInit(&obj->ms);
    return obj;    
}

void minStackPush(MinStack* obj, int x) {
    //��ջ
    StackPush(&obj->ds,x);
    //��Сջû�л�����Сֵ��ms��Top��С
    if(StackEmpty(&obj->ms) || x <=  StackTop(&obj->ms)){
        StackPush(&obj->ms,x);    
    }
}

void minStackPop(MinStack* obj) {
    //���������ȵĻ�,��ô����,����,һ��ds��
    if(StackTop(&obj->ms) == StackTop(&obj->ds)) {
       StackPop(&obj->ms); 
    }
       StackPop(&obj->ds); 
}

int minStackTop(MinStack* obj) {
   return StackTop(&obj->ds);
}

int minStackGetMin(MinStack* obj) {
   return StackTop(&obj->ms);
}

void minStackFree(MinStack* obj) {
    StackDestroy(&obj->ds);
    StackDestroy(&obj->ms);
    free(obj);
}