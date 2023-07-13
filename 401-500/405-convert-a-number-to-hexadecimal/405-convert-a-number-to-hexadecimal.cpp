class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string res;
        unsigned int n = num;

        while (n) {
            res.push_back(hex[n & 0xf]);
            n >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    string hex = "0123456789abcdef";
};