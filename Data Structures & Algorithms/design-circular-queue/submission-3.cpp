class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;
    int cap;    
    MyCircularQueue(int k) {
        this->cap = k + 1;
        arr = new int[k + 1];
        size = 0;
        front = 0;
        rear = 0;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            rear = (rear + 1) % cap;
            arr[rear] = value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            front = (front + 1) % cap;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!isEmpty()) return arr[(front + 1) % cap];
        return -1;
    }
    
    int Rear() {
        if(!isEmpty()) return arr[rear];
        return -1;
    }
    
    bool isEmpty() {
        return rear == front;
    }
    
    bool isFull() {
        return (rear + 1) % cap == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */