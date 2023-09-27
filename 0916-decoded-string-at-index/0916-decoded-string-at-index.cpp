class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int index = 0;
        long long total_length = 0;
        while (total_length < k) {
            if (isdigit(s[index])) {
                total_length *= s[index] - '0';
            } else {
                total_length ++;
            }
            ++index;
        }
        for (int i = index - 1; i >= 0; --i) {
            if (isdigit(s[i])) {
                total_length /= (s[i] - '0');
                k %= total_length;
            } else {
                if (k == 0 || k == total_length) {
                    return string(1, s[i]);
                }
                --total_length;
            }
        }
        return "";
            
    }
};