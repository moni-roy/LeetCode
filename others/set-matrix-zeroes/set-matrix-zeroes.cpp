class Solution
{
public:
    void setZeroes(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        set<int> rw, cl;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    rw.insert(i);
                    cl.insert(j);
                }
            }
        }
        for (auto r : rw)
        {
            for (int j = 0; j < n; j++)
            {
                mat[r][j] = 0;
            }
        }

        for (auto c : cl)
        {
            for (int i = 0; i < m; i++)
            {
                mat[i][c] = 0;
            }
        }
    }
};