class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = s.size()-2; i >= 0; i--) {
            shifts[i] += shifts[i+1]; 
            shifts[i] = shifts[i]%('z' - 'a' + 1);
        }
        for(int i = 0; i< s.size(); i++) {
            char c = (s[i] - 'a' + shifts[i])%('z' - 'a' + 1) + 'a';
            s[i] = c;
        }
        return s;
    }
};