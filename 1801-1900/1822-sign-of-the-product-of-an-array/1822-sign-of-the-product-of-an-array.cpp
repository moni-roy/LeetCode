class Solution {
public:
    int arraySign(vector<int>& nums) {
        int minus = 0;
        for(auto num: nums)  {
            if(num == 0) return 0;
            if(num < 0) minus ++;
        }
        return (minus & 1) ? -1 : 1;
    }
};