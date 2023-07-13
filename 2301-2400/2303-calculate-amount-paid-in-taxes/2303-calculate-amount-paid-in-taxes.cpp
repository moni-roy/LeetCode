class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        double tax = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (income <= brackets[i][0]) {
                tax += (income - prev) * brackets[i][1] / 100.0;
                break;
            }
            tax += (brackets[i][0] - prev) * brackets[i][1] / 100.0;
            prev = brackets[i][0];
        }
        return tax;
        
    }
};