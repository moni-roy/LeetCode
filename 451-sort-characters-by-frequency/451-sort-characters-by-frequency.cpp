class Solution {
public:
    string frequencySort(string s) {
        return frequencySortUsingMap(s);
    }
private:
    string frequencySortUsingMap(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        vector<pair<int, char>> v;
        for (auto p : m) {
            v.push_back(make_pair(p.second, p.first));
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string ans;
        for (auto p : v) {
            for (int i = 0; i < p.first; i++) {
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};