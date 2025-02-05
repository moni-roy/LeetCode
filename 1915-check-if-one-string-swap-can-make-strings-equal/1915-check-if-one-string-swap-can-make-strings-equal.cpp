class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n != m) return false;
        int diff = 0;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff++;
                idx.push_back(i);
            }
        }
        if (diff == 0) return true;
        if (diff != 2) return false;
        swap(s1[idx[0]], s1[idx[1]]);
        return s1 == s2;
    }
};