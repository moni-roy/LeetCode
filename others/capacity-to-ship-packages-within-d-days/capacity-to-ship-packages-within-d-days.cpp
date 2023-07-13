class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while(left < right) {
            int mid = (left + right) / 2;
            if(canShip(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool canShip(vector<int>& weights, int capacity, int days) {
        int cur = 0;
        for(int w : weights) {
            if(w > capacity) return false;
            if(cur + w > capacity) {
                days--;
                cur = 0;
            }
            cur += w;
        }
        return days > 0;
    }
};