class Solution {
public:
    int maximum69Number (int num) {
        string numS = to_string(num);
        int max = 0, flag = 0;
        for (int i = 0; i < numS.size(); i++) {
            if (!flag && numS[i] == '6') {
                max = max * 10 + 9;
                flag = 1;
            }
            else {
                max = max * 10 + numS[i] - '0';
            }
        }
        return max;
    }
private:
    int convertingStringUsingStream(int num) {
        int ans = 0;
        stringstream ss;
        ss << num;
        string s;
        ss >> s;
        int k = 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '6' && k) {
                ans = ans * 10 + 9;
                k--;
            }
            else ans = ans * 10 + (s[i] - '0');
        }
        return ans;   
    }
};