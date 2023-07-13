class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int l = s.size();
        vector<int> pre(l + 1, 0);
        for (int i = 0; i < l; i++)
        {
            pre[i + 1] = pre[i] + (s[i] == '1');
        }
        int ans = INT_MAX;
        for (int i = 0; i <= l; i++)
        {
            ans = min(ans, pre[i] + l - i - (pre[l] - pre[i]));
        }
        return ans;
    }
};