class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        for (auto candy : candies) {
            result.push_back(candy + extraCandies >= max);
        }
        return result;
    }
};