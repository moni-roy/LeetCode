class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int n = nums.size();
        
        auto mn = minmax_element(nums.begin(), nums.end());
        int low = *mn.first;
        int high = *mn.second;
        
        int gap = (high - low)/(n-1);
        gap = gap>1?gap:1;
        
        int bucket = (high-low)/gap + 1;
        vector<int> maxN(bucket, INT_MIN), minN(bucket, INT_MAX);
        
        for(auto num: nums) {
            int index = (num - low)/gap;
            maxN[index] = maxN[index]<num?num:maxN[index];
            minN[index] = minN[index]>num?num:minN[index];
        }
        
        int i = 0, j = 0;
        int ans = maxN[0] - minN[0];
        
        while(i<bucket) {
            j = i + 1;
            while(j<bucket && minN[j] == INT_MAX && maxN[j] == INT_MIN) {
                j++;
            }
            if(j == bucket) break;
            ans = ans < (minN[j] - maxN[i])? (minN[j] - maxN[i]) : ans;
            i = j;
        }
        return ans;
    }
};