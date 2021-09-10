class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<unordered_map<long long, long long> > dif(n);
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j < i; j++) {
                long long df = (long long)nums[i] - (long long)nums[j];
                long long tl = 0;
                
                if(dif[j].find(df) != dif[j].end()) {
                    tl = dif[j][df];
                }
                dif[i][df] += tl + 1;
                ans += tl;
            }
        }
        return ans;
    }
};