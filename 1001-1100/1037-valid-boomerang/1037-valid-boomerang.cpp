class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return checkSlope(points);
    }
private:
    bool checkSlope(vector<vector<int>>& points) {
        double slop1 = (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]);
        double slop2 = (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]);
        return !(slop1 == slop2);
    }
};