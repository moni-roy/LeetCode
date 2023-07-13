class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> points(questions.size(), -1);
        return func(questions, 0, points);
    }
private:
    long long func(vector<vector<int>>& questions, int pos, vector<long long>& points) {
        if (pos >= questions.size()) {
            return 0;
        }
        if (points[pos] != -1) {
            return points[pos];
        }
        long long res = 0;
        res = max(res, func(questions, pos + 1, points));
        res = max(res, questions[pos][0] + func(questions, pos + questions[pos][1] + 1, points));
        points[pos] = res;
        return res;
    }
};