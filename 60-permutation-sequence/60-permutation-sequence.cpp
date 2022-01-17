class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial = getFactorial(n);
        string res = "";
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        for (int i = 0; i < n; ++i) {
            int index = (k - 1) / factorial[n - i - 1];
            res += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k -= index * factorial[n - i - 1];
        }
        return res;
    }
private:
    vector<int> getFactorial(int n) {
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        return factorial;
    }
};