class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, h = numbers.size()-1;
        while(numbers[l] + numbers[h] != target) {
            if(numbers[l] + numbers[h] < target) l++;
            else h--;
        }
        return {l+1, h+1};
    }
};