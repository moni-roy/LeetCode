class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long long powerValue = 1;
        for (int i = 0; i < k-1; i++) {
            powerValue = (powerValue * power) % modulo;
        }
        long long hash = 0, pos = n;
        for(int i = n -1; i >= 0; i--) {
            hash = (hash * power + (s[i] - 'a' + 1)) % modulo;
            if (i <= n - k) {
                if (hash == hashValue) {
                    pos = i;
                }
                hash = (hash - powerValue * (s[i + k - 1] - 'a' + 1)) % modulo;
                if (hash < 0) {
                    hash += modulo;
                }
            }
        }
        return s.substr(pos, k);
    }
};