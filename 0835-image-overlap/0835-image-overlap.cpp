class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> oneImg1, oneImg2;
        unordered_map<int, int> count;
        int n = img1.size();
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) oneImg1.push_back(i * n * 100 + j % n);
                if (img2[i][j] == 1) oneImg2.push_back(i * n * 100 + j % n);
            }
        }
        
        for (auto i1 : oneImg1) {
            for (auto i2 : oneImg2) count[i1 - i2] ++;
        }
        int ans = 0;
        for(auto it : count) ans = max(ans, it.second);
        return ans;
    }
};