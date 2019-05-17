#include "Queue.h"
#include<stdio.h>
#include <malloc.h>
#include <assert.h>
void QueueInit(Queue *pq) {
	assert(pq);
	pq->front = pq->rear = NULL;
}
void QueueDestroy (Queue *pq){
	QueueNode *PNode = NULL;
	assert(pq);
	PNode = pq->front;
	while(PNode->next){
		pq->front = PNode->next;
		free(PNode);
		PNode = pq->front;
	}
	pq->front = pq->rear = NULL;
}
QueueNode *BuyNode(DataType data){
	QueueNode *NewNode = (QueueNode*)malloc (sizeof(QueueNode));
	if(NewNode == NULL){
		assert(0);
	}
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
void QueuePush (Queue *pq,DataType data){
	QueueNode *NewNode = NULL;
	assert(pq);
	NewNode  = BuyNode (data);
	if(QueueEmpty (pq)){
		pq->front = pq->rear = NewNode;
	}
	else {
		pq->rear->next = NewNode;
		pq->rear = NewNode;
	}
}
void Queuepop(Queue *pq){
	QueueNode * pDeleNode = NULL;
	assert(pq);
	if(QueueEmpty (pq)){
		return ;
	}	
	pDeleNode = pq->front;
	if(pDeleNode->next == NULL){
		pq->front = pq->rear = NULL;
	}
	else {
		pq->front = pDeleNode->next;
	}
	free(pDeleNode);
}
DataType Queuetail(Queue *pq) {
	assert(pq);
	return pq->rear->data;
}
int QueueEmpty (Queue *pq){
	assert(pq);
	return NULL == pq->front;
}
DataType QueueHead(Queue *pq){
	assert(pq);
	return pq->front->data;
}
int QueueSize(Queue *pq){
	QueueNode * Temp = NULL;
	int  size = 0;
	assert(pq);
	Temp = pq->front;
	while(Temp){
		size++;
		Temp = Temp->next;
	}
	return size;
}
void TestQueue(){

	Queue pq;
	QueueInit (&pq);
	QueuePush (&pq,1);
	QueuePush (&pq,2);
	QueuePush (&pq,3);


	Queuepop(&pq);
	printf("%d\n",Queuetail (&pq));
	printf("%d\n",QueueSize (&pq));

	Queuepop (&pq);
	printf("%d\n",QueueHead (&pq));
	
}

int main (){

	TestQueue ();	
	return 0;
}



