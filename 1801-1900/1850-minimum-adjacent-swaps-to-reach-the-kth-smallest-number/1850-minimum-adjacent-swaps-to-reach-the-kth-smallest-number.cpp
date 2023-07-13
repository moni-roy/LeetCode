class Solution {
public:
    int getMinSwaps(string num, int k) {
        string original = num;
        while (k--) {
            next_permutation(num.begin(), num.end());
        }
        return getMinSwaps(num, original);
    }
private:
    int getMinSwaps(string num, string original) {
        int ans = 0;
        int n = num.size();
        int i = 0, j = 0;
        while (i < n) {
            j = i;
            while (j < n && num[j] != original[i]) {
                j++;
            }
            while (i < j) {
                swap(num[j], num[j-1]);
                j--;
                ans++;
            }
            i++;
        }
        return ans;
    }
};