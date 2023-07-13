class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int store[m+1][n+1];
        memset(store, 0, sizeof store);
        
        for (auto s: strs) {
            int nz = 0 , no = 0;
            for(auto c: s) {
                if(c == '0') nz++;
                else no ++;
            }
            
            for(int i = m; i>=nz; i--) {
                for(int j = n; j >= no; j--) {
                    store[i][j] = max(store[i][j], store[i - nz][j - no] + 1);
                }
            }
        }
        return store[m][n];
    }
};