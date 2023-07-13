class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        if (points.size() == 0 || points[0].size() == 0) return res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push(make_pair(dis, i));
        }
        for (int i = 0; i < k; i++) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};