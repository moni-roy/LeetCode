class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> countTop(7, 0), countBottom(7, 0), countSame(7, 0);
        for (int i = 0; i < n; ++i) {
            countTop[tops[i]]++;
            countBottom[bottoms[i]]++;
            if (tops[i] == bottoms[i])
                countSame[tops[i]]++;
        }
        
        for (int i = 1; i <= 6; ++i) {
            if (countTop[i] + countBottom[i] - countSame[i] == n)
                return n - max(countTop[i], countBottom[i]);
        }
        return -1;
    }
};