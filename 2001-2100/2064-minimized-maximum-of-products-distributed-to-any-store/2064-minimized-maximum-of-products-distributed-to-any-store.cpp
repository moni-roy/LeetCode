class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        return minimizedMaximumUsingBS(n, quantities);
    }
private:
    int minimizedMaximumUsingBS(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        while (l < r) {
            int m = l + (r - l) / 2;
            if (canBeMade(m, quantities, n)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    bool canBeMade(int m, vector<int>& quantities, int n) {
        int stores = 0;
        for (int i = 0; i < quantities.size(); ++i) {
            stores += (quantities[i] + m - 1) / m;
        }
        return stores <= n;
    }
};