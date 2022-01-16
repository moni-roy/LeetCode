class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> points(questions.size(), -1);
        return func(questions, 0, points);
    }
private:
    long long func(vector<vector<int>>& questions, int l, vector<long long>& points) {
        if (l >= questions.size()) {
            return 0;
        }
        if (points[l] != -1) {
            return points[l];
        }
        long long res = 0;
        res = max(res, func(questions, l + 1, points));
        res = max(res, questions[l][0] + func(questions, l + questions[l][1] + 1, points));
        points[l] = res;
        return res;
    }
};