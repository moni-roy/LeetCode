class Solution {
public:
    string frequencySort(string s) {
        return frequencySortWithoutSort(s);
    }
private:
    string frequencySortUsingMapAndSort(string s) {
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
    string frequencySortWithoutSort(string s) {
        unordered_map<char, int> freq;
        for (char c: s) {
            freq[c]++;
        }
        vector<string> bucket(s.size() + 1, "");
        for (auto p: freq) {
            bucket[p.second].append(p.second, p.first);
        }
        string ans="";
        for (int i = bucket.size() - 1; i >= 0; i--) {
            ans.append(bucket[i]);
        }
        return ans;
    }
};