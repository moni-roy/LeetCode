class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int> > rows;
        for(int i = 0; i < mat.size(); i++) {
            int sol = 0;
            for(auto t: mat[i]) sol += t;
            rows.push_back({sol, i});
        }
        sort(rows.begin(), rows.end());
        vector<int> ans;
        
        for(int i = 0; i < k; i++) ans.push_back(rows[i].second);
        return ans;
    }
};