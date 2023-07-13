class RangeModule {
public:
    map<int, int> intervals;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        auto it2 = intervals.upper_bound(right);
        if (it != intervals.begin()) {
            it--;
            if(it->second < left) it++;
        }
        if(it != it2) {
            left = min(left, it->first);
            right = max(right, prev(it2)->second);
            it2 = intervals.erase(it, it2);
        }
        intervals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin() || prev(it)->second < right) return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        auto it2 = intervals.upper_bound(right);
        if (it != intervals.begin()) {
            it--;
            if(it->second < left) it++;
        }
        if(it != it2) {
            int l = min(left, it->first);
            int r = max(right, prev(it2)->second);
            it2 = intervals.erase(it, it2);
            if(l < left) intervals[l] = left;
            if(right < r) intervals[right] = r;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */