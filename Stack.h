#pragma  once

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