class Solution {
public:
    double average(vector<int>& salary) {
        int mx = salary[0];
        int mn = salary[0];
        double sum = 0;
        for(auto sal: salary) {
            sum += sal;
            mx = max(mx, sal);
            mn = min(mn, sal);
        }
        sum -= (mx+mn);
        return sum / (salary.size() - 2);
        
    }
};