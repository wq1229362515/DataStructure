#pragma once 

typedef int DataType;


typedef struct QueueNode {

	DataType data;
	struct QueueNode *next;

}QueueNode;

typedef struct Queue {

	struct QueueNode *front;
	struct QueueNode *rear;

}Queue;


void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);
void QueuePush (Queue *pq,DataType data);
void Queuepop(Queue *pq);
DataType Queuetail(Queue *pq);
int QueueEmpty (Queue *pq);
DataType QueueHead(Queue *pq);
int QueueSize(Queue *pq);

