class MyCalendar {
public:
    vector<pair<int,int> > v;
    MyCalendar() {
        v.clear();
    }
    
    bool book(int start, int end) {
        for(auto e: v) {
            if(isConflict(e, start, end)) return false;
        }
        v.push_back({start, end});
        return true;
    }
    
    bool isConflict(pair<int, int> x, int s, int e) {
        if((x.first >= e) ||(s >= x.second)) return false;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */