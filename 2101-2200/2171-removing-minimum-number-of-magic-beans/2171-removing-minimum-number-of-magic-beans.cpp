class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n = beans.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += beans[i];
        }
        sort (beans.begin(), beans.end());
        long long ans = sum;
        for (int i = 0; i < n; ++i) {
            long long cur = sum - beans[i] * (n - i);
            if (cur < ans) {
                ans = cur;
            }
        }
        
        return ans;
    }
};