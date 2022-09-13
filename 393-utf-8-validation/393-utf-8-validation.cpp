class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool res = true;
        int n = data.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int mask = 1 << 7;
            while (mask & data[i]) {
                ++cnt;
                mask >>= 1;
            }
            if (cnt == 0) continue;
            if (cnt == 1 || cnt > 4) return false;
            if (i + cnt > n) return false;
            for (int j = i + 1; j < i + cnt; ++j) {
                if ((data[j] >> 6) != 2) return false;
            }
            i += cnt - 1;
        }
        return res;
    }
};