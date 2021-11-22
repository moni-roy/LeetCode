class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (auto &word : words) {
            if (is_expressive(s, word)) res++;
        }
        return res;
    }

    bool is_expressive(string s, string word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                int cnt = 1;
                while (i < s.size() - 1 && s[i] == s[i + 1]) {
                    cnt++;
                    i++;
                }
                int cnt2 = 1;
                while (j < word.size() - 1 && word[j] == word[j + 1]) {
                    cnt2++;
                    j++;
                }
                if (cnt < 3 && cnt != cnt2 || cnt < cnt2) return false;
                i++;
                j++;
            } else {
                return false;
            }
        }
        return i == s.size() && j == word.size();
    }
};