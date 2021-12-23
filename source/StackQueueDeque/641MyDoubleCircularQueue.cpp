class MyCircularDeque {
private: vector<int> vec;int front,rear,capacity;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k):vec(k+1),front(0),rear(0),capacity(k+1) {
        ;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(!isFull()){
            front = (front -1 +capacity) % capacity;
            vec[front] = value;
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(!isFull()){
            vec[rear] = value;//rear空标记，需要先填写再+1后移
            rear = (rear + 1)% capacity;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(!isEmpty()){
            front = (front + 1)% capacity;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(!isEmpty()){
            //rear空标记，需要先填写再+1后移
            rear = (rear -1 + capacity)% capacity;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(!isEmpty()){
            return vec[front];
        };
        return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(!isEmpty()){
            return vec[(rear - 1 + capacity )% capacity];//rear空标记，所以拿出来前面一个
        }
        return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(rear == front){
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if((rear+1) % capacity == front){
            return true;
        }
        return false;
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