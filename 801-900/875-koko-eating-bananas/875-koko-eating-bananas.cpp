class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return minEatingSpeedUsingBS(piles, h);   
    }
private:
    int minEatingSpeedUsingBS(vector<int> &piles, int h) {
        int n = piles.size();
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canEatAll(piles, h, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    bool canEatAll(vector<int> &piles, int h, int k) {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += (piles[i] + k - 1) / k;
        }
        return sum <= h;
    }
};