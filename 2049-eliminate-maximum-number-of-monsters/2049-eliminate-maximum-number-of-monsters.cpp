class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float, vector<float>, greater<float>> arrival_time;
        for (int i = 0; i < dist.size(); i++) {
            arrival_time.push(dist[i] * 1.0 / speed[i]);
        }
        int ans = 0;
        while (!arrival_time.empty()) {
            if (ans >= arrival_time.top()) break;
            ans ++;
            arrival_time.pop();
        }
        return ans;
    }
};