class Solution {
public:

    int calculate(string s) {
        stack<int> operands;
        long num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (sign == '+') {
                    operands.push(num);
                } else if (sign == '-') {
                    operands.push(-num);
                } else if (sign == '*') {
                    int t = operands.top();
                    operands.pop();
                    operands.push(t * num);
                } else if (sign == '/') {
                    int t = operands.top();
                    operands.pop();
                    operands.push(t / num);
                }
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!operands.empty()) {
            res += operands.top();
            operands.pop();
        }
        return res;
    }
};