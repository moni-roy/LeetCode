class Solution {
public:
    int maxRepeating(string sequence, string word) {
        return usingLinearSearch(sequence, word);
    }
private:
    int usingLinearSearch(string sequence, string word) {
        string temp = word;
        int ans = 0;
        while(sequence.find(temp) != string::npos) {
            ans ++;
            temp += word;
        }
        return ans;
    }
};