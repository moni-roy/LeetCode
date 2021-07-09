class Solution {
public:
    int lengthOfLIS(vector<int>& seq) {
        int sz = seq.size();
        int check[2501];
        int ln = 1, mn = 0;
        check[0] = seq[0];
        for (int k = 1; k < sz; k++) {
        if (check[ln - 1] < seq[k]) {
          check[ln++] = seq[k];
        }
        else {
          mn = lower_bound(check, check + ln, seq[k]) - check;
          check[mn] = seq[k];
        }
        }
        return ln;
        
    }
};