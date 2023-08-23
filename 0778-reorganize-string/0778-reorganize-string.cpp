class Solution {
public:
    string reorganizeString(string s) {
        vector <int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int max_cnt = *max_element(cnt.begin(), cnt.end());
        if (max_cnt > (s.length() + 1) / 2) return "";
        int max_idx = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == max_cnt) {
                max_idx = i;
                break;
            }
        }
        int idx = 0;
        string ans = s;
        while (cnt[max_idx]) {
            ans[idx] = max_idx + 'a';
            idx += 2;
            cnt[max_idx]--;
        }
        for (int i = 0; i < 26; i++) {
            while (cnt[i]) {
                if (idx >= s.length()) idx = 1;
                ans[idx] = i + 'a';
                idx += 2;
                cnt[i]--;
            }
        }
        return ans;
    }
};