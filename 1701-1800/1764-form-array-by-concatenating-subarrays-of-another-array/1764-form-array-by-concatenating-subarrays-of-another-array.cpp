class Solution
{
public:
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {
        int idx = 0, grId = 0;
        while (idx < nums.size() && grId < groups.size())
        {
            bool flag = true;
            for (int i = 0; i < groups[grId].size(); i++)
            {
                if (idx + i >= nums.size())
                {
                    flag = false;
                    break;
                }
                if (nums[idx + i] != groups[grId][i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                idx += groups[grId].size();
                grId++;
            }
            else
            {
                idx++;
            }
        }
        return grId == groups.size();
    }
};