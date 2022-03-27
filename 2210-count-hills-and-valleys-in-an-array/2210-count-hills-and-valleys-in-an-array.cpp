class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int>uniques;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                uniques.push_back(nums[i]);
            }
            else{
                if(nums[i] != nums[i-1]){
                    uniques.push_back(nums[i]);
                }
            }
        }
        for(int i = 1; i < uniques.size() - 1; i++){
            if(uniques[i] < uniques[i-1] && uniques[i] < uniques[i+1]){
                count++;
            }
            else if(uniques[i] > uniques[i-1] && uniques[i] > uniques[i+1]){
                count++;
            }
        }
        return count;
    }
};