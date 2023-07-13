class Solution {
public:
    int countVowelStrings(int n) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return dfs(0, n, &vowels);
    }
private:
    int dfs(int start, int n, vector<char> *vowels) {
        if(n == 0) return 1;
        int res = 0;
        for(int i = start; i < vowels->size(); i++) {
            res += dfs(i, n - 1, vowels);
        }
        return res;
    }
};