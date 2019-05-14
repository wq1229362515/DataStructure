#include <stdio.h>
#include "SQLIST.h"
#include <malloc.h>
#include <assert.h>
void sqlistNode_init(sqlist_Head *Head){
	(*Head) = NULL;	
}
sqlistNode* BuysqlistNode (Datatype data ) {
	sqlistNode * Node = NULL;
	Node = (sqlistNode *)malloc (sizeof(sqlistNode));
	Node->data = data;
	Node->Next = NULL;
	return Node;
}
void sqlistNode_popBack(sqlist_Head *Head,Datatype data) {
	sqlistNode* NewNode = NULL;
	assert(Head);
	NewNode = BuysqlistNode (data);
	if(*Head == NULL){
		(*Head) = NewNode;
		return ;
	}
	else {
		sqlistNode *Node = (*Head);
		while(Node->Next) {
			Node = Node->Next;
		}
		Node->Next = NewNode;
	}
}
void sqlist_Print(sqlist_Head *Head) {
	sqlistNode *Node = NULL;
	assert(Head);
	Node = (*Head);
	while(Node) {
		printf("%d-->",Node->data);
		Node = Node->Next;
	}
	printf("NULL\n");
}
void sqlistNode_pushBack(sqlist_Head *Head){
	sqlistNode * Node = NULL;
	sqlistNode * Temp = NULL;
	assert(Head);
	if((*Head)->Next == NULL){
		free(*Head);
		(*Head) = NULL;
		return ;
	}
	Node = (*Head);
	while(Node->Next){
		Temp = Node;
		Node = Node->Next;
	}
	free(Node);
	Node = Temp;
	Node->Next = NULL;
	Temp = NULL;



}
void sqlistNode_popFront(sqlist_Head *Head,Datatype data){
	sqlistNode * NewNode = NULL;
	assert(Head);
	if(*Head == NULL) {
		(*Head) = BuysqlistNode (data);
		return ;
	}
	NewNode = (sqlistNode *)malloc(sizeof(sqlistNode));
	NewNode->data = (*	Head)->data;
	(*Head)->data = data;
	NewNode->Next = (*Head)->Next;
	(*Head)->Next = NewNode;
}
void sqlistNode_pushFront(sqlist_Head *Head){
	sqlistNode *Node = NULL;
	assert(Head);
	if((*Head)->Next == NULL){
		free(*Head);
		(*Head) = NULL;
		return ;
	}
	Node = (*Head)->Next;
	free(*Head);
	(*Head) = Node;
}
sqlistNode * sqlistNodeFind(sqlist_Head *Head,Datatype data){
	sqlistNode *Node = NULL;
	assert(Head);
	Node = (*Head);
	while(Node){
		if(Node->data == data){
			return Node;
		}
		else {
			Node = Node->Next;
		}
	}
	return NULL;
}
void sqlistNode_Dele_Node(sqlist_Head *Head,sqlistNode* pos){
	sqlistNode *Node = NULL;
	sqlistNode *Temp = NULL;
	assert(Head);
	Node = (*Head)->Next;
	Temp = Node;
	if((*Head) == pos){
		(*Head) = Node;
	}
	while(Node){
		if(Node == pos){
			Temp->Next = pos->Next;
			free(pos);
			pos = NULL;
			return ;
		}
		else {
			Temp = Node;
			Node = Node->Next;
		}
	}
}
void sqlistNode_insert_Node(sqlistNode *pos,Datatype data){
	sqlistNode* Node = BuysqlistNode (data);
	if(pos->Next == NULL){
		Node = pos->Next;
		Node->Next = NULL;
	}
	else {
		Node->Next = pos->Next;
		pos->Next = Node;
	}
}
void sqlistNoderemoveallNode(sqlist_Head *Head,Datatype data) {
	sqlistNode *Node = NULL;
	sqlistNode *Temp = NULL;
	assert(Head);
	/*Node = (*Head);
	while(Node) {		
		if((*Head)->data == data){
			sqlistNode_pushFront (Head);
			continue;
		}
		Node = (*Head);
			while(Node->Next){
				if(Node->Next->data == data){
					Temp = Node->Next;	
					Node->Next = Temp->Next;
					free(Temp);
				}
				else {
					Node = Node->Next;
				}
			}
			return ;
		}*/
	
	Temp = (*Head);
	Node = (*Head);
	if((*Head)->Next == NULL && (*Head)->data == data) {
		Temp = Temp->Next;
		free(*Head);
		(*Head) = Temp;
		return;
	}
	while(Node){
		if(Temp->data == data) {
			Node = Node->Next;
			free(Temp);
			(*Head) = Temp = Node;
		}
		else if(Node->data == data){
			Temp->Next= Node->Next;
			free(Node);
			Node = Temp->Next;
		}
		else {
			Temp = Node;
			Node = Node->Next;
		}
	 }
	}
void sqlistClear(sqlist_Head *Head) {
	sqlistNode *Node = NULL;
	assert(Head);
	Node = (*Head)->Next;
	while(Node) {
		(*Head)->Next = Node->Next;
		free(Node);
		Node = (*Head)->Next;
	}
}
void sqlistDestroy(sqlist_Head *Head){
	assert(Head);
	sqlistClear (Head);
	free(*Head);
	(*Head) = NULL;
}
sqlistNode* sqlist_revers(sqlist_Head *Head){
	sqlistNode *Node1 = NULL;
	sqlistNode *Node2 = NULL;
	if(!Head){
		return ;
	}
	Node2 = (*Head);
	while((*Head)){
		Node2 = (*Head)->Next;
		(*Head)->Next = Node1;
		(Node1) = (*Head);
		(*Head) = Node2;	
	}
	
	return Node1;
}
sqlistNode * Sqlist_DeledoubleNode(sqlist_Head *Head){
	sqlistNode *Temp = NULL;
	sqlistNode *Pre = NULL;
	sqlistNode *Node = NULL;
	if(Head == NULL){
		return  *Head;
	}
	Node = (*Head);
	Temp = (*Head)->Next;
	while(Temp){
		if(Node->data == Temp->data ){
			free(Node);
			Node = Temp;
			Temp= Temp->Next;
			free(Node);
			Node = Temp;
			Temp = Temp->Next;
			Pre->Next = Node;
		}
		else{
			Pre = Node;
			Node = Node->Next;
			Temp = Temp->Next;
		}
	}
			
	return (*Head);
}

void SqlistNode_Test() {

	sqlistNode* s;
	sqlistNode* p;
	sqlistNode_init (&s);
	/*sqlistNode_popBack (&s,1);
	sqlistNode_popBack(&s,2);
	sqlist_Print (&s);

	sqlistNode_pushBack(&s);
	sqlist_Print (&s);

	sqlistNode_pushBack(&s);
	sqlist_Print (&s);


	sqlistNode_popBack (&s,4);
	sqlistNode_popBack(&s,2);
	sqlistNode_popBack (&s,3);
	sqlistNode_popBack(&s,4);
	sqlist_Print (&s);

	sqlistNode_popFront(&s,0);
	sqlist_Print (&s);


	sqlistNode_pushFront(&s);
	sqlist_Print (&s);

	p = sqlistNodeFind (&s,3);
	sqlistNode_Dele_Node (&s,p);
	sqlist_Print (&s);


	p = sqlistNodeFind (&s,2);
	sqlistNode_insert_Node(p,3);
	sqlist_Print (&s);
	*/
	sqlistNode_popBack(&s,1);
	sqlistNode_popBack(&s,2);
	sqlistNode_popBack(&s,3);
	sqlistNode_popBack(&s,3);
	sqlistNode_popBack(&s,4);
	sqlistNode_popBack(&s,4);
	sqlistNode_popBack(&s,5);
	sqlist_Print (&s);
	Sqlist_DeledoubleNode(&s);
	sqlist_Print (&s);
	/*sqlistNoderemoveallNode(&s,1);
	sqlist_Print (&s);*/

	//sqlistClear(&s);
	//sqlist_Print (&s);

	/*sqlistDestroy(&s);
	sqlist_Print (&s);*/
}
int main () {
	SqlistNode_Test ();
	return 0;
}

