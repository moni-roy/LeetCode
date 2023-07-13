class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, ret = 0;
        while (i < chars.size()) {
            int cnt = 1;
            while (i + cnt < chars.size() && chars[i + cnt] == chars[i]) cnt ++;
            chars[ret++] = chars[i];
            if (cnt > 1) {
                for (auto c : to_string(cnt)) {
                    chars[ret++] = c;
                }
            }
            i += cnt;
        }
        return ret;
    }
};