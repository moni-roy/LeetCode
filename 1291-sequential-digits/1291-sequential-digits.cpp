class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int n = 1;
        while (n <= 9) {
            int num = n, d = n + 1;
            while (num <= high && d <= 10) {
                if (num >= low) res.push_back(num);
                num = num * 10 + (d++);
            }
            n++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};