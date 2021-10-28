class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int n = n1 + n2;
        vector<int> res(n, 0);
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];
                res[p1] += sum / 10;
                res[p2] = sum % 10;
            }
        }
        string s;
        for (int i = 0; i < n; i++) {
            if (i == 0 && res[i] == 0) continue;
            s += res[i] + '0';
        }
    
        // remove leading 0 from the string
        int i = 0;
        while (i < s.size() && s[i] == '0') i++;
        s = s.substr(i);
        return s.empty() ? "0" : s;
    }
};