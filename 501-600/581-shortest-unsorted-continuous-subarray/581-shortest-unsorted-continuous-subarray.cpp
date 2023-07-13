class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(n);
        for (int i = 0; i < n; i++) {
            sorted[i] = nums[i];
        }
        sort(sorted.begin(), sorted.end());
        int start = 0;
        int end = n - 1;
        while (start < n && nums[start] == sorted[start]) {
            start++;
        }
        while (end > start && nums[end] == sorted[end]) {
            end--;
        }
        return end - start + 1;
    }
};