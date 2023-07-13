class Solution {
public:
    string removeDuplicates(string s) {
        string ret = "";
        stack<char> st;
        for(char c: s) {
            if(!st.empty() && st.top() == c) {
                st.pop();
            }
            else st.push(c);
        }
        while(!st.empty()) {
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};