typedef struct {
    int *array; 
    int size;   //记录有效元素个数
    int capacity;
    int front;  //队头的位置
    int back;   //队尾的位置
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if(NULL == q) {
        assert(0);
        return NULL;
    }
    q->array = (int *)malloc(sizeof(int)*k);
    if(q->array == NULL) {
        assert(0);
        return NULL;
    }
    q->size = 0;
    q->capacity = k;
    q->front = 0;
    q->back = 0;
    return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //队列满和队列未满
    assert(obj);
    //满了
    if(obj->size == obj->capacity) {
        return false;
    }
    //未满的情况
    obj->array[obj->back++] = value;
    obj->size++;
    if(obj->back == obj->capacity) {
        obj->back = 0;
    }
    return true;
    
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    //检测队列是否为空
    if(0 == obj->size){
        return false;
    }
    obj->front++;
    if(obj->front ==  obj->capacity){
        obj->front = 0;
    }
    obj->size--;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->size == 0) {
        return -1;
    }
    return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->size == 0) {
        return -1;
    }
    //队尾位置满了那么back就回到对头了
    if(obj->back == 0){
        return obj->array[obj->capacity-1];
    }
    return obj->array[obj->back-1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
   return 0 == obj->size;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);
}