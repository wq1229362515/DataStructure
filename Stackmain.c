#include "Stack.h"
#include <stdio.h>
#include<malloc.h>
#include <assert.h>

void Stackininit(StackNode *Stack ){	
	assert(Stack);
	Stack->arr = (Datadype*)malloc (sizeof(Datadype)*5);
	if(Stack->arr ==NULL){
		assert(0);
		return;
	}
	Stack->capacity = 5;
	Stack->top = 0;
}
void StackPush (StackNode *Stack,Datadype data){
	assert(Stack);
	if(Stack->top == Stack->capacity){
		int Newcapacity = 2*Stack->capacity;
		int i;
		Datadype *NewStack;
		NewStack = (Datadype *)malloc(sizeof(Datadype)*Newcapacity);
		for(i = 0;i<Stack->top;i++){
			NewStack[i] = Stack->arr[i];
		}
		free(Stack->arr);
		Stack->arr = NewStack;
		Stack->capacity = Newcapacity;
	}		
	
	Stack->arr[Stack->top] = data;	
	Stack->top++;
}
void StackPop(StackNode *Stack){
	assert(Stack);
	if(Stackempty (Stack)){
		return ;
	}
	Stack->top--;

}
Datadype StackTop(StackNode *Stack) {
	assert(Stack);
	return Stack->arr[Stack->top-1];
}
int Stackempty(StackNode *Stack){
	assert(Stack);
	return 0 == Stack->top;
}
int StackSize(StackNode *Stack){
	assert(Stack);
	return Stack->top;
}
void StackDestroy(StackNode *Stack) {
	assert(Stack);
	if(Stack->arr){
		free(Stack->arr);
		Stack->top = 0;
		Stack->capacity = 0;
	}
	
	
}
void TestStack (){
	StackNode ps;
	Stackininit (&ps);
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
	printf("%d\n",Stackempty (&ps));
	StackDestroy(&ps);
}
int main (){
	TestStack();
	return 0;
}