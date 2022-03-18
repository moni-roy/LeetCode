class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        vector<int> visited(26, 0);
        for (char c : s) ++freq[c - 'a'];
        string res = "";
        for (char c : s) {
            --freq[c - 'a'];
            if (visited[c - 'a']) continue;
            while (res.back() > c && freq[res.back() - 'a']) {
                visited[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res += c;
            visited[c - 'a'] = 1;
        }
        return res;
    }
};