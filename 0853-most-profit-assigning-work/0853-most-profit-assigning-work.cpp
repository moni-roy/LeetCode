class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobs;
        jobs.push_back({0, 0});
        for (int i = 0; i < difficulty.size(); i++) {
            jobs.push_back({profit[i], difficulty[i]});
        }
        sort(jobs.begin(), jobs.end());
        reverse(jobs.begin(), jobs.end());
        for (int i = 0; i < jobs.size() - 1; i++) {
            jobs[i + 1].second =
                min(jobs[i].second, jobs[i + 1].second);
        }

        int netProfit = 0;
        for (int i = 0; i < worker.size(); i++) {
            int ability = worker[i];
            int l = 0, r = jobs.size() - 1, jProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobs[mid].second <= ability) {
                    jProfit = max(jProfit, jobs[mid].first);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            netProfit += jProfit;
        }
        return netProfit;
    }
};