class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> mem(m + 1, vector<int>(n + 1, 1e7));
        return calculate(dungeon, mem, 0, 0);
    }

    int calculate(vector<vector<int>> &mat, vector<vector<int>> &mem, int ix, int iy)
    {
        int m = mat.size();
        int n = mat[0].size();
        if (ix >= m || iy >= n)
            return 1e7;
        if (ix == m - 1 && iy == n - 1)
        {
            return (mat[ix][iy] <= 0) ? -mat[ix][iy] + 1 : 1;
        }

        if (mem[ix][iy] != 1e7)
            return mem[ix][iy];
        int ret = min(calculate(mat, mem, ix + 1, iy), calculate(mat, mem, ix, iy + 1)) - mat[ix][iy];
        return mem[ix][iy] = (ret <= 0) ? 1 : ret;
    }
};