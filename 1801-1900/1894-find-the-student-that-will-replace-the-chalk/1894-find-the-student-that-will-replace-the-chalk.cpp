class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0ll);
        int res = 0, n = chalk.size();
        k = k % sum;
        for (int i = 0; i < n; ++i) {
            if(k < chalk[i]) {
                res = i;
                break;
            }
            k -= chalk[i];
        }
        return res;
    }
};