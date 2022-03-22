class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        for(int i = n - 1; i >= 0; --i) {
            int add = min(26, k - i);
            res[i] = add + 'a' - 1;
            k -= add;
        }
        return res;
    }
};