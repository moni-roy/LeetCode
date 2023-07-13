class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int cur = 0;
        for (int i = 0; i < events.size();) {
            auto &e = events[i];
            if (pq.empty()) {
                cur = e[0];
            }
            while (i < events.size() && events[i][0] <= cur) {
                pq.push(events[i][1]);
                i++;
            }
            pq.pop();
            ans++;
            cur++;
            while (!pq.empty() && pq.top() < cur) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            pq.pop();
            ans++;
            cur++;
            while (!pq.empty() && pq.top() < cur) {
                pq.pop();
            }
        }
        
        return ans;
    }
};