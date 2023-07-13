class Solution {
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> count(10001, 0);
        for (int num : nums)
            count[num]++;
        int prev = 0, cur = 0;

        for (int i = 0; i < 10001; i++)
        {
            int temp = cur;
            cur = max(prev + i * count[i], cur);
            prev = temp;
        }
        return cur;
    }
};