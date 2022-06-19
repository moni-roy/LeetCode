class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        int cnt[10] = {0};
        for (int i = 0; i < n; ++i) {
            cnt[num[i] - '0']++;
        }
        for (int i = 0; i < n; ++i) {
            if (cnt[i] != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};