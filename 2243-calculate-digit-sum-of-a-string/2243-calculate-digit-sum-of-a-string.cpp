class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string t = "";
            for(int i = 0; i < s.size(); i += k) {
                string sub = s.substr(i, k);
                int sum = 0;
                for(int j = 0; j < sub.size(); j++) {
                    sum += sub[j] - '0';
                }
                t += to_string(sum);
            }
            s = t;
        }
        return s;
    }
};