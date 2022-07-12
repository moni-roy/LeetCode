class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int div = sum / 4;
        if (div * 4 != sum) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> per(4, 0);
        return dfs(0, matchsticks, per, div);
    }
    
    bool dfs(int pos, vector<int>& matchsticks, vector<int> &per, int &div) {
        if (pos == matchsticks.size()) {
            return per[0] == per[1] && per[1] == per[2] && per[2] == div;
        }
        for (int i = 0; i < 4; i++) {
            if (per[i] + matchsticks[pos] <= div) {
                int j = i;
                while (--j >= 0) {
                    if(per[i] == per[j]) break;
                }
                if (j == -1) {
                    per[i] += matchsticks[pos];
                    if (dfs(pos + 1, matchsticks, per, div)) {
                        return true;
                    }
                    per[i] -= matchsticks[pos];
                }
            }
        }
        return false;
    }
};