#include "Stack.h"
#include <stdio.h>
#include<malloc.h>
#include <assert.h>

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
void TestStack (){
	Stack ps;
	StackInit (&ps);
	StackPush(&ps,1);
	StackPush(&ps,2);
	//StackPop(&ps);
	//printf("%d\n",StackTop (&ps));
	//Stackempty (&ps);
	StackPush(&ps,3);
	StackPush(&ps,4);
	StackPush(&ps,5);
	StackPush(&ps,6);
	StackPop (&ps);
	printf("%d\n",StackTop(&ps));
	printf("%d\n",StackSize (&ps));
	printf("%d\n",StackEmpty (&ps));
	StackDestroy(&ps);
}
int main (){
	TestStack();
	return 0;
}
