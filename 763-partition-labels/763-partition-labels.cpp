class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int n = s.size();
        vector<int> last(26, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        int j = 0, k = 0;
        for (int i = 0; i < n; ++i) {
            j = max(j, last[s[i] - 'a']);
            if (i == j) {
                res.push_back(i - k + 1);
                k = i + 1;
            }
        }
        return res;
    }
};