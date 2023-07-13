class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(0);
            } else {
                int cur = st.top();
                st.pop();
                int pre = st.top();
                st.pop();
                st.push(pre + max(2 * cur, 1));
            }
        }
        return st.top();
    }
};