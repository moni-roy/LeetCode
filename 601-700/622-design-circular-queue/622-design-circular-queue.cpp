class MyCircularQueue {
private:
    vector<int> data;
    int head, tail;
    bool exist;
    
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = tail = 0;
        exist = false;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        exist = true;
        data[tail] = value;
        tail = (tail + 1) % data.size();
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % data.size();
        if (head == tail) exist = false;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return data[(tail + data.size() - 1) % data.size()];
    }
    
    bool isEmpty() {
        if (head == tail && !exist) return true;
        return false;
        
    }
    
    bool isFull() {
        if (head == tail && exist) return true;
        return false;
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