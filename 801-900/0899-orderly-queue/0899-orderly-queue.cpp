class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ans = s;
            for (int i = 0; i < s.size(); ++i) {
                string t = s.substr(i) + s.substr(0, i);
                if (t < ans) ans = t;
            }
            return ans;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};