class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        runDFS(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
private:
    void runDFS(vector<vector<int>>& image, int sr, int sc, int newColor, int color) {
        image[sr][sc] = newColor;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto dir : dirs) {
            int nr = sr + dir[0];
            int nc = sc + dir[1];
            if (nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size() && image[nr][nc] == color) {
                runDFS(image, nr, nc, newColor, color);
            }
        }
    }
};