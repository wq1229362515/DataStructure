typedef int DataType;


typedef struct QueueNode {

	int data;
	struct QueueNode *next;

}QueueNode;

typedef struct Queue {

	struct QueueNode *front;
	struct QueueNode *rear;

}Queue;


void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);
void QueuePush (Queue *pq,int data);
int QueuePop(Queue *pq);
int QueueTail(Queue *pq);
int QueueEmpty (Queue *pq);
DataType QueueHead(Queue *pq);
int QueueSize(Queue *pq);



void QueueInit(Queue *pq) {
	assert(pq);
	pq->front = pq->rear = NULL;
}
void QueueDestroy (Queue *pq){
	QueueNode *PNode = NULL;
	assert(pq);
	PNode = pq->front;
	while(PNode){
		pq->front = PNode->next;
		free(PNode);
		PNode = pq->front;
	}
	pq->front = pq->rear = NULL;
}
QueueNode *BuyNode(int data){
	QueueNode *NewNode = (QueueNode*)malloc (sizeof(QueueNode));
	if(NewNode == NULL){
		assert(0);
	}
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
void QueuePush (Queue *pq,int data){
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
int QueuePop(Queue *pq){
    int temp = 0;
	QueueNode * pDeleNode = NULL;
	assert(pq);
	/*if(QueueEmpty (pq)){
		return ;
	}*/	
	pDeleNode = pq->front;
	if(pDeleNode->next == NULL){
		pq->front = pq->rear = NULL;
	}
	else {
		pq->front = pDeleNode->next;
	}
    temp = pDeleNode->data;
	free(pDeleNode);
    return temp;
}
DataType QueueTail(Queue *pq) {
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


typedef struct {
    Queue ps1;
    Queue ps2; 
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {      
    //把栈的结构体变量创建出来
    //不能这样给MyStack obj;
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    if(obj == NULL) {
        assert(0);
        return NULL;
    }
    QueueInit(&obj->ps1);
    QueueInit(&obj->ps2);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    assert(obj);
    
    if(!QueueEmpty(&obj->ps1)) {
        QueuePush(&obj->ps1,x);
    }
    else {
        QueuePush(&obj->ps2,x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int  myStackPop(MyStack* obj) {
    assert(obj);
    if(!QueueEmpty(&obj->ps1)){
        //q1的前n-1元素移动到p2
        int size = QueueSize(&obj->ps1);
        while(size>1){
            QueuePush(&obj->ps2,QueueHead(&obj->ps1));
            QueuePop(&obj->ps1);
            size--;
        }
        int ret = QueueTail(&obj->ps1);
        QueuePop(&obj->ps1);
        return ret;
    }
    else {
         //ps2的前n-1元素移动到ps1中
        int size = QueueSize(&obj->ps2);
        while(size>1){
            QueuePush(&obj->ps1,QueueHead(&obj->ps2));
            QueuePop(&obj->ps2);
            size--;
        }
        int ret = QueueTail(&obj->ps2);
        QueuePop(&obj->ps2);
        return ret;
    }
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(QueueEmpty(&obj->ps1) == 1) {
        return QueueTail(&obj->ps2);
    }
        return QueueTail(&obj->ps1);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->ps1)&&QueueEmpty(&obj->ps2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->ps1);
    QueueDestroy(&obj->ps2);
    free(obj);
}