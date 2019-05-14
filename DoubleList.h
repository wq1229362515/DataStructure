#pragma once

typedef int DLdataType;

typedef struct DlistNode {

	DLdataType data;
	struct DlistNode *P_Next;
	struct DlistNode *P_pre;
}DlistNode,*Dlist_Head;
//初始化,尾插,尾删,头插,头删
void DlistNode_Init(Dlist_Head *Head);
void DlistNode_PopBack(Dlist_Head *Head,DLdataType data);
void DlistNode_PushBack(Dlist_Head *Head);
void DlistNode_PopFront(Dlist_Head *Head,DLdataType data);
void DlistNode_PushFront (Dlist_Head *Head);

DlistNode* DlistNode_FindNode(Dlist_Head *Head,DLdataType data);
//任意位置的后插入
void DlistNode_InsterNode(DlistNode *Pos,DLdataType data);
void DlsitNode_DeleNode(DlistNode *Pos);

void DlistNode_ClearList(Dlist_Head *Head);

void DlistNode_DestroyList(Dlist_Head *Head);


void DlistNode_RmovALL(Dlist_Head *Head,DLdataType data);