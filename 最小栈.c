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


//栈是不能遍历的,没有遍历的操作
//push o(1)
//pop  o(1)
//top  o(1)
//getmin o(1)


//一次可以从栈里面放两个元素
//第一个元素代表最小值
//第二个元素代表数据
//栈顶元素 获取top就行了 
//出栈一次出两个


//两个栈 , s1保存数据  ,s2 放置最小值
/*
入栈 :
    s1 每次都需要入一个元素
    s2 data<=最小值
    s2 也要入元素
出栈:
    s1 每次都需要出一个元素
    s2 相等的情况下两个都出
    不相等时候s1 出一个元素
*/


typedef struct {
    Stack ds;
    Stack ms;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    //MinStack obj  临时变量在函数所在的栈区上, 函数结束后就返回了
    //是一个临时变量,函数运行结束,这个变量就销毁了
    //通过malloc放到堆上面去
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
    //入栈
    StackPush(&obj->ds,x);
    //最小栈没有或者最小值比ms的Top还小
    if(StackEmpty(&obj->ms) || x <=  StackTop(&obj->ms)){
        StackPush(&obj->ms,x);    
    }
}

void minStackPop(MinStack* obj) {
    //两个如果相等的话,那么都出,否则,一个ds出
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