class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> st, ts;
        for(int i = 0; i<s.size(); i++) {
            if(st.find(s[i]) == st.end() && ts.find(t[i]) == ts.end()) {
                st[s[i]] = t[i];
                ts[t[i]] = s[i];
            }
            else if(st[s[i]] != t[i] || ts[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};