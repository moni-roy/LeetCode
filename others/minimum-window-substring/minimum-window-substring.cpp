class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> tm, am;

        int uni = 0;
        for (auto c : t)
        {
            if (tm[c] == 0)
                uni++;
            tm[c]++;
        }
        int l = 0, r = 0, cnt = 0;
        vector<int> ans(2, -1);
        
        while (r < s.size())
        {
            char c = s[r];
            am[c]++;
            if (tm[c] && am[c] == tm[c])
                cnt++;
            while (l <= r && cnt == uni)
            {
                c = s[l];
                if (ans[0] == -1 || (r - l + 1) < ans[0])
                {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                }
                am[c]--;
                if (tm[c] && am[c] < tm[c])
                    cnt--;
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};