class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int i = 0, j = s.size() - 1;

        while(i < j) {
            while(i < j && vowels.find(s[i]) == string::npos) {
                i++;
            }
            while(i < j && vowels.find(s[j]) == string::npos) {
                j--;
            }
            if(i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};