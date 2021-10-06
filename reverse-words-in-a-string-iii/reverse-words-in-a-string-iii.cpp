class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "";
        string r;
        int  i = 0;
        while(ss>>r) {
            if(i) ans +=" ";
            reverse(r.begin(), r.end());
            ans += r;
            i++;
        }
        return ans;
    }
};