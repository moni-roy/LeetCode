class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;
        for(auto n: nums) {
            if(st.find(n - 1) == st.end()) {
                int t = n;
                int c = 1;
                while(st.find(t + 1) != st.end()){
                    t += 1;
                    c += 1;
                }
                ans = ans > c ? ans: c;
            }
        }
        return ans;
    }
};