class Solution {
public:
    bool isPossible(vector<int>& nums) {
        return makeConsecutiveSubsequenceUsingMap(nums);
    }
private:
    bool makeConsecutiveSubsequenceUsingMap(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        unordered_map<int, int> hasPrev;
        for (int num : nums) {
            if (count[num] == 0) {
                continue;
            }
            if (hasPrev.count(num - 1) && hasPrev[num - 1] > 0) {
                hasPrev[num - 1]--;
                hasPrev[num]++;
            } else if (count.count(num + 1) && count[num + 1] > 0 && count[num + 2] > 0 ) {
                count[num + 1]--;
                count[num + 2]--;
                hasPrev[num + 2]++;
            } else {
                return false;
            }
            count[num]--;
        }
        return true;
    }
};