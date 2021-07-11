class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> sm, la;
    MedianFinder() {
    }
    
    void addNum(int num) { 
        sm.push(num);
        la.push(-sm.top());
        sm.pop();
        if(sm.size() < la.size()) {
            sm.push(-la.top());
            la.pop();
        }
    }
    
    double findMedian() {
        return sm.size() > la.size() ? sm.top() : (sm.top() - la.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */