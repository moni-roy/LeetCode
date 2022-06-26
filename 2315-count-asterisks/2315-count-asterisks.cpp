class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        vector<int> stars;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                ++cnt;
            }
            if(s[i] == '|') {
                stars.push_back(cnt);
                cnt = 0;
            }
        }
        stars.push_back(cnt);
        int res = 0;
        for (int i = 0; i < stars.size(); i += 2) {
            res += stars[i];
        }
        return res;
    }
};