class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto p: s) {
            if(p == '(') st.push(')');
            else if(p == '{') st.push('}');
            else if(p == '[') st.push(']');
            else if(st.empty() ||  st.top() != p) return false;
            else st.pop();
        }
        return st.empty();
    }
};