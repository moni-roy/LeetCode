class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "";
        string rev;
        while (ss >> rev) {
            reverse(rev.begin(), rev.end());
            ans = ans + " " + rev;
        }
        return ans.substr(1);
    }
};