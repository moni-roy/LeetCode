class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        queue<int> oddIndices;
        int subarrays = 0, lastPopped = -1, initialGap = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                oddIndices.push(i);
            }
            if (oddIndices.size() > k) {
                lastPopped = oddIndices.front();
                oddIndices.pop();
            }
            if (oddIndices.size() == k) {
                initialGap = oddIndices.front() - lastPopped;
                subarrays += initialGap;
            }
        }

        return subarrays;
    }
};