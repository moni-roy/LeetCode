class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mp;
        for (auto& w : words) {
            int cnt = 0;
            for (auto& c : w) {
                cnt |= 1 << (c - 'a');
            }
            mp[cnt]++;
        }
        vector<int> res;
        for (auto& p : puzzles) {
            int first = 1 << (p[0] - 'a');
            int sum = mp[first];

            int mask = 0;
            for (auto& c : p.substr(1)) {
                mask |= 1 << (c - 'a');
            }
            for(int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                sum += mp[sub|first];
            }
            res.push_back(sum);
        }
        return res;
    }
};