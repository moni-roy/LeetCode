#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
    string decodeString(string& s, int &index) {
        string res="";
        while (index < s.size() && s[index]!=']') {
            if (isdigit(s[index])) {
                int num = 0;
                while (index < s.size() && isdigit(s[index])) {
                    num = num * 10 + s[index] - '0';
                    index++;
                }
                index++;
                string tmp = decodeString(s, index);
                index++;
                while (num--) res += tmp;
            }
            else {
                res += s[index++];
            }
        }
        return res;
    }
};
