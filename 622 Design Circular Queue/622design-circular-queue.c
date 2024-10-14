
typedef struct {
    int *array;       
    int front;     
    int rear;     
    int size;     
    int cap; 
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    obj->array=(int*)malloc(k*sizeof(int));
    obj->front=-1;
    obj->rear=-1;
    obj->size=0;
    obj->cap=k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size==obj->cap)
    {
        return false;
    }
    if(obj->size==0)
    {
        obj->front=0;
    }
    obj->rear=(obj->rear+1)%obj->cap;
    obj->array[obj->rear]=value;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->size==0)
    {
        return false;
    }
    if(obj->front==obj->rear)
    {
        obj->front=-1;
        obj->rear=-1;
    }else{
        obj->front=(obj->front+1)%obj->cap;
    }
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->size==0)
    {
        return -1;
    }
    return obj->array[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->size==0)
    {
        return -1;
    }
    return obj->array[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size==0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size==obj->cap;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/