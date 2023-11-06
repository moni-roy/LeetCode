class SeatManager {
private:
    set<int> reserved_seat, unreserved_seat;
public:
    SeatManager(int n) {
        
    }
    
    int reserve() {
        if (reserved_seat.empty() && unreserved_seat.empty()) {
            reserved_seat.insert(1);
            return *reserved_seat.rbegin();
        }
        int next;
        if(unreserved_seat.empty()) next = *reserved_seat.rbegin() + 1;
        else {
            next = *unreserved_seat.begin();
            unreserved_seat.erase(unreserved_seat.find(next));
        }

        reserved_seat.insert(next);
        return next;
    }
    
    void unreserve(int seatNumber) {
        unreserved_seat.insert(seatNumber);
        reserved_seat.erase(reserved_seat.find(seatNumber));
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */