class MyCalendar {
public:
    vector<pair<int, int> > events;
    
    MyCalendar() {
        events.clear();
    }
    
    bool book(int start, int end) {
        for (auto event : events) {
            if (isConflict(event, start, end)) return false;
        }
        events.push_back({start, end});
        return true;
    }
    
    bool isConflict(pair<int, int> event, int start, int end) {
        if ((event.first >= end) || (start >= event.second)) return false;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */