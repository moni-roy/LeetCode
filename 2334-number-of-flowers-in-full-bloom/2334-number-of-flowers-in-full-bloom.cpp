class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> pre_sum;
        pre_sum[0] = 0;
        for (auto flower: flowers) {
            pre_sum[flower[0]]++;
            pre_sum[flower[1] + 1]--;
        }
        vector<int> result, positions, counts;
        int count = 0;
        for (auto& mp: pre_sum) {
            positions.push_back(mp.first);
            count += mp.second;
            counts.push_back(count);
        }

        for (auto p: people) {
            int up = upper_bound(positions.begin(), positions.end(), p) - positions.begin();
            result.push_back(counts[up - 1]);
        }
        return result;
    }
};