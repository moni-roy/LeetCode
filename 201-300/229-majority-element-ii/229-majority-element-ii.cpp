class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int firstMajor = INT_MAX, secondMajor = INT_MAX, firstCount = 0, secondCount = 0;
        
        for(auto n: nums) {
            if(firstMajor == n) firstCount ++;
            else if (secondMajor == n) secondCount ++;
            else if(firstCount == 0) firstMajor = n, firstCount = 1;
            else if (secondCount == 0) secondMajor = n, secondCount = 1;
            else firstCount--, secondCount--;
        }
        firstCount = 0, secondCount = 0;
        for(auto n: nums) {
            if(n == firstMajor) firstCount++;
            else if(n == secondMajor) secondCount++;
        }
        if(firstCount*3 > nums.size() && secondCount*3 > nums.size()) {
            return {firstMajor, secondMajor};
        }
         if(firstCount*3 > nums.size()) {
            return {firstMajor};
        }
        if(secondCount*3 > nums.size()) {
            return {secondMajor};
        }
        return {};
    }
};