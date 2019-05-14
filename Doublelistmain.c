#include <stdio.h>
#include "DoubleList.h"
#include <malloc.h>
#include <assert.h>
void DlistNode_Init(Dlist_Head *Head){
	assert(Head);
	(*Head) = (DlistNode*)malloc (sizeof(DlistNode));
	if(*Head == NULL){
		assert(0);
		return;
	}
	(*Head)->P_Next = (*Head);
	(*Head)->P_pre = (*Head);
}
DlistNode * BuyDlistNode(DLdataType data) {
	DlistNode *Add_NewNode = NULL;
	Add_NewNode = (DlistNode *)malloc (sizeof(DlistNode));
	if(Add_NewNode  == NULL){
		assert(0);
	}
	Add_NewNode->data = data;
	Add_NewNode->P_Next = NULL;
	Add_NewNode->P_pre = NULL;
	return Add_NewNode;
}
void DlistPrint(Dlist_Head *Head) {
	DlistNode *Node = NULL;
	if(*Head == NULL){
		assert(0);
		return ;
	}
	Node = (*Head)->P_Next;
	while(Node != (*Head)){
		printf("%d-->",Node->data);
		Node = Node->P_Next;
	}
	printf("NULL\n");
}
void DlistNode_PopBack(Dlist_Head *Head,DLdataType data){
	DlistNode *Add_NewNode = NULL;
	if(*Head == NULL) {
		assert(0);
		return;
	}
	Add_NewNode = BuyDlistNode(data);	
	Add_NewNode->P_pre = (*Head)->P_pre;
	Add_NewNode->P_pre->P_Next = Add_NewNode;
	Add_NewNode->P_Next = (*Head);
	(*Head)->P_pre = Add_NewNode;
}
//尾删
void DlistNode_PushBack(Dlist_Head *Head){
	DlistNode *EndNode = NULL;
	if(*Head == NULL){
		assert(0);
		return ;
	}
	EndNode = (*Head)->P_pre;
	(*Head)->P_pre = EndNode->P_pre;
	EndNode->P_pre->P_Next = (*Head);
	free(EndNode);
	EndNode = NULL;
}
void DlistNode_PopFront(Dlist_Head *Head,DLdataType data){
	DlistNode *AddNewNode = NULL;
	if(*Head == NULL){
		assert(0);
		return ;
	}
	AddNewNode = BuyDlistNode (data);
	AddNewNode->P_pre = (*Head);
	AddNewNode->P_Next = (*Head)->P_Next;
	(*Head)->P_Next->P_pre = AddNewNode;
	(*Head)->P_Next = AddNewNode;
}
void DlistNode_PushFront (Dlist_Head *Head){
	DlistNode * FristNode = NULL;
	if(*Head == NULL){
		assert(0);
		return ;
	}
	FristNode = (*Head)->P_Next;
	(*Head)->P_Next = FristNode->P_Next;
	FristNode->P_Next->P_pre = (*Head);
	free(FristNode);
	FristNode = NULL;
}

DlistNode* DlistNode_FindNode(Dlist_Head *Head,DLdataType data){
	DlistNode *Node = NULL;
	if(*Head == NULL) {
		assert(0);
	}
	Node = (*Head)->P_Next;
	while(Node != (*Head)){
		if(Node->data == data){
			return Node;
		}
		else {
			Node = Node->P_Next;
		}
	}
	return NULL;
}
//任意位置的后插入
void DlistNode_InsterNode(DlistNode *Pos,DLdataType data){
	DlistNode *NewNode = NULL;
	assert(Pos);
	NewNode = BuyDlistNode (data);	
	Pos->P_Next->P_pre = NewNode;
	NewNode->P_Next = Pos->P_Next;
	Pos->P_Next = NewNode;
	NewNode->P_pre = Pos;
}
void DlsitNode_DeleNode(DlistNode *Pos) {
	DlistNode *Node  = NULL;
	assert(Pos);
	Pos->P_Next->P_pre = Pos->P_pre;
	Pos->P_pre->P_Next = Pos->P_Next;
	free(Pos);
	Pos = NULL;
}

void DlistNode_ClearList(Dlist_Head *Head){
	DlistNode *Node = NULL;
	if(*Head == NULL){
		assert(0);
		return ;
	}
	Node = (*Head)->P_Next;
	while(Node != (*Head)){
		(*Head)->P_Next = Node->P_Next;
		free(Node);
		Node = (*Head)->P_Next;
	}
}

void DlistNode_DestroyList(Dlist_Head *Head){
	if(*Head == NULL ){
		assert(0);
		return ;
	}
	DlistNode_ClearList(Head);
	free(*Head);
	(*Head) = NULL;	
}
//采取的是一种不断向前的策略,定义两个指针,一个在前,一个在后,
//如果相等先完成连接操作(使后面的指向前面的下一个,完成他们的连接(完成前面的下一个和后面指针的连接,进而空出那个相等的))
// 释放Node = Temp->Next
//如果再相等就继续操作
//不相等的话两个向前移动
void DlistNode_RmovALL(Dlist_Head *Head,DLdataType data){
	DlistNode * Node  = NULL;
	DlistNode *Temp =  NULL;
	if(*Head == NULL){
		assert(0);
	}
	Temp = (*Head);
	Node = (*Head)->P_Next;
	while(Node != (*Head)){
		if(Node->data == data){
			Temp->P_Next = Node->P_Next;
			Node->P_Next->P_pre = Temp;
			free(Node);
			Node = Temp->P_Next;
		}
		else {
			Temp = Node;
			Node = Node->P_Next;
		}
	}
}


void DlistNode_Test(){
	DlistNode *s;
	//DlistNode *p;
	DlistNode_Init (&s);
	/*DlistNode_PopBack (&s,0);
	DlistNode_PopBack (&s,1);
	DlistPrint (&s);
    
	DlistNode_PushBack(&s);
	DlistPrint (&s);

	DlistNode_PopFront(&s,2);
	DlistPrint (&s);

	DlistNode_PushFront(&s);
	DlistPrint (&s);*/
	
	//DlistNode_PopBack (&s,1);
	//DlistNode_PopBack (&s,5);
	//DlistNode_PopBack (&s,6);
	//DlistNode_PopBack (&s,7);
	//DlistNode_PopBack (&s,8);
	//DlistNode_PopBack (&s,3);
	//
	////查找
	//p = DlistNode_FindNode (&s,1);
	//DlistNode_InsterNode (p,10);

	//p = DlistNode_FindNode (&s,10);
	//DlsitNode_DeleNode(p);


	////DlistNode_ClearList (&s);
	//DlistNode_DestroyList (&s);



	DlistNode_PopBack (&s,1);
	DlistNode_PopBack (&s,2);
	DlistNode_PopBack (&s,1);
	DlistNode_PopBack (&s,3);
	DlistNode_PopBack (&s,8);
	DlistNode_PopBack (&s,1);


	DlistNode_RmovALL(&s,1);

	DlistPrint (&s);
	
}
int main2 (){

	DlistNode_Test();
	return ;
}