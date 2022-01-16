class ExamRoom {
public:
    vector<int> seats;
    int N;
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        if(seats.empty()) {
            seats.push_back(0);
            return 0;
        }
        int dist = max(seats[0], N - seats.back() - 1);
        for (int i = 1; i < seats.size(); ++i) {
            dist = max(dist, (seats[i] - seats[i - 1])/2);
        }
        if (dist == seats[0]) {
            seats.insert(seats.begin(), 0);
            return 0;
        }
        int pos = -1;
        for (int i = 1; i < seats.size(); ++i) {
            if(dist == (seats[i] - seats[i - 1])/2) {
                pos = i;
                break;
            }
        }
        if(pos != -1) {
            seats.insert(seats.begin() + pos, seats[pos - 1] + dist);
            return seats[pos - 1] + dist;
        }
        seats.push_back(N-1);
        return N - 1;
        
    }
    
    void leave(int p) {
        int pos = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if(seats[i] == p) {
                pos = i;
                break;
            }
        }
        seats.erase(seats.begin() + pos);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */