class MyCircularDeque {
    private:
    vector<int>dq;
    int front,back,cap,s;
public:
    MyCircularDeque(int k) {
        dq.assign(k,-1);
        front=0;
        back=0;
        s=0;
        cap=k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(front==0) front=cap-1;
        else front--;
        dq[front]=value;
        s++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        dq[back]=value;
        if(back==cap-1) back=0;
        else back++;
        s++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        dq[front]=-1;
        if(front==cap-1) front=0;
        else front++;
        s--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(back==0) back=cap-1;
        else back--;
        dq[back]=-1;
        s--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return dq[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        if(back==0)
        return dq[cap-1];
        else return dq[back-1];
    }
    
    bool isEmpty() {
        return s==0;
    }
    
    bool isFull() {
        return s==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */