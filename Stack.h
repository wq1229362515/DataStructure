#pragma  once

typedef int Datadype;

typedef struct stackNode {
	Datadype *arr;
	int top;
	int capacity;
}StackNode;



void Stackininit(StackNode *Stack );
void StackPush (StackNode *Stack,Datadype data);
void StackPop(StackNode *Stack);
Datadype StackTop(StackNode *Stack);
int Stackempty(StackNode *Stack);
void StackDestroy(StackNode *Stack);
