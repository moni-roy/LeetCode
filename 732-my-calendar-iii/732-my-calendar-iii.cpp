class MyCalendarThree {
private:
    unordered_map<int, int> vals, lazy;
    void update(int p, int s, int e, int x, int y) {
        if (s > y || e < x) return;
        if (s <= x && y <= e) {
            vals[p] ++;
            lazy[p] ++;
            return;
        }
        int m = (x + y) / 2;
        update(p * 2, s, e, x, m);
        update(p * 2 + 1, s, e, m + 1, y);
        vals[p] = lazy[p] + max(vals[p * 2], vals[p * 2 + 1]);
    }
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        update(1, start, end - 1, 1, 1000000001);
        return vals[1];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */