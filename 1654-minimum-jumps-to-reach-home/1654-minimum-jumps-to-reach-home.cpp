class Solution
{
public:
    const int inf = 1e9;

    unordered_set<int> set;

    int dp[6005][2];

    int go(int pos, int target, int fwd, int bwd, int cnt)
    {
        if (pos == target)
            return 0;

        if (set.find(pos) != set.end() or pos < 0 or pos > 6000)
            return inf;

        if (dp[pos][cnt] != -1)
            return dp[pos][cnt];

        dp[pos][cnt] = 1 + go(pos + fwd, target, fwd, bwd, 0);
        dp[pos][cnt] = min(dp[pos][cnt], (cnt) ? 1 + go(pos + fwd, target, fwd, bwd, 0) : 1 + go(pos - bwd, target, fwd, bwd, 1));

        return dp[pos][cnt];
    }

    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        for (int ele : forbidden)
            set.insert(ele);

        memset(dp, -1, sizeof dp);
        int ans = go(0, x, a, b, 0);
        return (ans >= 1e9) ? -1 : ans;
    }
}; // from internet