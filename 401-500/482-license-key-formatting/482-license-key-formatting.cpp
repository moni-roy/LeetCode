class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;
            if (count == k) {
                ans.push_back('-');
                count = 0;
            }
            ans.push_back(toupper(s[i]));
            count++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};