class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int cur = 0;
        for (auto& course : courses) {
           if (cur + course[0] <= course[1]) {
               cur += course[0];
               pq.push(course[0]);
           } else if (!pq.empty() && pq.top() > course[0]) {
               cur += course[0] - pq.top();
               pq.pop();
               pq.push(course[0]);
           }
        }
        return pq.size();
    }
};