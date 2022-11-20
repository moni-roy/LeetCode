class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0) return 0;
        
        int result = 0;
        int sign = 1;
        int num = 0;

        stack<int> st;
        st.push(sign);

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];

            if(c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');

            } else if(c == '+' || c == '-') {
                result += sign * num;
                sign = st.top() * (c == '+' ? 1: -1); 
                num = 0;

            } else if(c == '(') {
                st.push(sign);

            } else if(c == ')') {
                st.pop();
            }
        }

        result += sign * num;
        return result;
    }
};
