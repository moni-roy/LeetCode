class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        ans[0].push_back(1);
        for(int i = 1; i<numRows; i++) {
            ans[i].push_back(1);
            for(int j = 0; j<i;j++) {
                int t = ans[i-1][j] + (((j+1) == i)? 0: ans[i-1][j+1]);
                ans[i].push_back(t);
            }
        }
        return ans;
    }
};