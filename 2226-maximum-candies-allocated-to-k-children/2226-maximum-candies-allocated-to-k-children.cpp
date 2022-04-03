class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end()), ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = 0;
            for (int candy : candies) {
                sum += candy / mid;
            }
            if (sum >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};