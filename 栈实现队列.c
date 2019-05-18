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


//s1 入队列 (入栈)
//s2 出队列 (出栈)


//入队列 直接放s1
//出队列 检测s2 是否有数据,如果没有数据那么导数据到s2


typedef struct {
    Stack s1;   //模拟实现入队列
    Stack s2;   //模拟出队列
    
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    if(obj == NULL) {
        assert(0);
        return NULL;
    }
    StackInit(&obj->s1);
    StackInit(&obj->s2);
    return obj;
    
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    StackPush(&obj->s1,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    assert(obj);
    if(StackEmpty(&obj->s2)) {
        //将s1中的元素搬移到s2中
        while(!StackEmpty(&obj->s1)) {
            StackPush(&obj->s2,StackTop(&obj->s1));
            StackPop(&obj->s1);
        }
        
    }
    int ret = StackTop(&obj->s2);
    StackPop(&obj->s2);
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
       if(StackEmpty(&obj->s2)) {
        //将s1中的元素搬移到s2中
        while(!StackEmpty(&obj->s1)) {
            StackPush(&obj->s2,StackTop(&obj->s1));
            StackPop(&obj->s1);
        }
        
    }
    return StackTop(&obj->s2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->s1)&&StackEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->s1);
    StackDestroy(&obj->s2);
    free(obj);
}
