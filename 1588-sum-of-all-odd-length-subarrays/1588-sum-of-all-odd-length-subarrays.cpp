class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int len = 1; len <= n; len += 2) {
            for(int i = 0; i < n; ++i) {
                for (int j = i; j < i + len && i + len <= n; ++j) {
                    res += arr[j];
                }
            }
        }
        return res;
    }
};