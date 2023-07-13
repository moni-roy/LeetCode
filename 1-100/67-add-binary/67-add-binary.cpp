class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";
        int i = 0, j = 0;
        int c = 0;
        while(i < a.size() || j < b.size()) {
            int x = 0, y = 0;
            if(i < a.size()) x = a[i++] - '0';
            if(j < b.size()) y = b[j++] - '0';
            int t = x + y + c;
            c = t/2;
            res += (t%2 + '0');
        }
        if(c) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};