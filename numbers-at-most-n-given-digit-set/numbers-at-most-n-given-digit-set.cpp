#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int len = digits.size();
        if (len == 0) return 0;
        string s = to_string(n);
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            string cur = s.substr(i, 1);
            for (auto d : digits) {
                if (d > cur) continue;
                if (d == cur) {
                    dp[i] += dp [i + 1];
                } else {
                    dp[i] += pow(digits.size(), s.size() - i - 1);
                }
            }
        }
        for (int i = 1; i < s.size(); ++i) {
            dp[0] += pow(digits.size(), i);
        }
        return dp[0];
    }

};