class Solution {
public:
    int nextGreaterElement(int n) {
        return usingBackward(n);
    }
private:
    int usingBackward(int n) {
        string s = to_string(n);
        int len = s.size();
        int i = len - 1;
        while (i > 0 && s[i] <= s[i - 1]) {
            --i;
        }
        if (i == 0) {
            return -1;
        }
        int j = len - 1;
        while (s[j] <= s[i - 1]) {
            --j;
        }
        swap(s[i - 1], s[j]);
        sort(s.begin() + i, s.end());
        long long res = stoll(s);
        return res > INT_MAX ? -1 : res;
    }
};