class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> indexes;
        vector<char> symbols;
        indexes.push_back(-1);
        symbols.push_back('L');
        int n = dominoes.size();
        
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                indexes.push_back(i);
                symbols.push_back(dominoes[i]);
            }
        }
    
        indexes.push_back(n);
        symbols.push_back('R');
        
        string ans(dominoes);
        for (int i = 0; i < indexes.size() - 1; i++) {
            int ix = indexes[i], iy = indexes[i + 1];
            char cx = symbols[i], cy = symbols[i + 1];
            if (cx == cy) {
                for (int j = ix + 1; j < iy; j++) ans[j]= cx;
            }
            else if (cx > cy) {
                for (int j = ix + 1; j < iy; j++) ans[j]= (j - ix) == (iy - j) ? '.' : j - ix < iy - j ? 'R' : 'L';
            }
        }
        return ans;
        
    }
};