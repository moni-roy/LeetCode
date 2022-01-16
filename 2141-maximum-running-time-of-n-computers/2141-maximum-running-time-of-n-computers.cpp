class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long min_battery = *min_element(batteries.begin(), batteries.end());
        if(n == batteries.size()) return min_battery;

        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long low = min_battery, high = sum / n, res = min_battery;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(can_use(mid, batteries, n)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }

    bool can_use(long long time, vector<int>& batteries, long long n) {
        long long time_used = 0;
        for(int i = 0; i < batteries.size(); i++) {
            time_used += min(time, (long long)batteries[i]);
        }
        return time_used >= time * n;
    }
};