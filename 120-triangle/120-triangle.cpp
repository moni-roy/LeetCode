class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector <int> mn = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mn[j] = triangle[i][j] + min(mn[j],mn[j+1]);
        return mn[0];
    }
};