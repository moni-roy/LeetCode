class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = -1, n = num.size();
        string res = "";
        for(int i = 0; i < n - 2; i++) {
            if(num[i] == num[i + 1] && num[i] == num[i + 2]) {
                int t = stoi(num.substr(i, 3));
                if(t > mx) {
                    mx = t;
                    res = num.substr(i, 3);
                }
            }
        }
        return res;
    }
};