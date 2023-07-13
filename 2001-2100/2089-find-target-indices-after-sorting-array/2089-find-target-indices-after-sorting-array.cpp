class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        int less = 0, same = 0;
        for(auto n: nums) {
            if(n < target) less++;
            if(n == target) same++;
        }
        for(int i = 0; i < same; i++) res.push_back(less++);
        return res;
    }
};