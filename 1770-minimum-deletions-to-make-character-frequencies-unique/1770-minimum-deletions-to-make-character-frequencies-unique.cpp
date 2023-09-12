class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int res = 0;
        int max_cnt = s.size();
        for (int cn : cnt) {
            if (cn > max_cnt) {
                res += cn - max_cnt;
                cn = max_cnt;
            }
            max_cnt = max(cn - 1, 0);
        }
        return res;
    }
};