class Solution
{
public:
    int dp[1001]={-1};
    
    int numDecodings(string s, int ps = 0)
    {
        if (ps == s.size())
            return 1;

        if (s[ps] == '0')
            return 0;
        
        if(dp[ps] >0) return dp[ps];

        int ret = numDecodings(s, ps + 1);
        if (ps < s.size() - 1 && (s[ps] == '1' || (s[ps] == '2' && s[ps + 1] < '7')))
        {
            ret += numDecodings(s, ps + 2);
        }
        return dp[ps] = ret;
    }
};