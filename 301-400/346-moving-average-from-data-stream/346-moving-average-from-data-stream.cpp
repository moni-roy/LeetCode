class MovingAverage {
public:
    int window, sum, currSize;
    queue<int> qu;
    MovingAverage(int size) {
        window = size;
        currSize = 0;
        sum = 0;
        
    }
    
    double next(int val) {
        qu.push(val);
        sum += val;
        if(currSize < window) currSize ++;
        else {
            sum -= qu.front();
            qu.pop();
        }
        return (sum + 0.0) / currSize * 1.0;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */