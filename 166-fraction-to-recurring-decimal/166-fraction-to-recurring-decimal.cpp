class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += '-';
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        res += to_string(num / den);
        num %= den;
        if (num == 0) return res;
        res += '.';
        unordered_map<long long, int> m;
        m[num] = res.size();
        while (num) {
            num *= 10;
            res += to_string(num / den);
            num %= den;
            if (m.find(num) != m.end()) {
                res.insert(m[num], 1, '(');
                res += ')';
                break;
            }
            m[num] = res.size();
        }
        return res;
    }
};