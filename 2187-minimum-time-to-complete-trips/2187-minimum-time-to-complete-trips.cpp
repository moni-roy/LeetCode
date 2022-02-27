class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = 1e15;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (check(time, totalTrips, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
private:
    bool check(vector<int>& time, int totalTrips, long long mid) {
        long long cur = 0;
        for (int i = 0; i < time.size(); ++i) {
            long long t = mid / time[i];
            cur += t;
            if (cur >= totalTrips) {
                return true;
            }
        }
        return false;
    }
};