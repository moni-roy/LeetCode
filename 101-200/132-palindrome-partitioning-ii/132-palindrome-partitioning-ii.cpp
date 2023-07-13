class Solution {
public:
    int minCut(string s) {
        vector<int> mnC(s.size());
        for(int i = 0; i < s.size(); i++) mnC[i] = i;
        for(int i = 0; i < s.size(); i++) {
            findMinCut(i, i, s, mnC);
            findMinCut(i-1, i, s, mnC);
        }
        return mnC[s.size() - 1];
        
    }
    void findMinCut(int s, int e, string &A, vector<int> &mnC) {
        for(int x = s, y = e; x>=0 && y<A.size() && A[x] == A[y]; x--, y++) {
            int mC = x == 0 ? 0 : mnC[x-1] + 1;
            mnC[y] = min(mnC[y], mC);
        }
    }
};