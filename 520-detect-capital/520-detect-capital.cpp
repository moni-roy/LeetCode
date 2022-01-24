class Solution {
public:
    bool detectCapitalUse(string word) {
        return checkGreedily(word);
    }
private:
    bool checkGreedily(string &word) {
        // check if all upper
        int totalUpper = 0;
        for(auto c: word) {
            if(isupper(c)) totalUpper ++;
            else if(totalUpper > 1) return false; // all or single uppercase
        }
        if(totalUpper == 1 && isupper(word[0])) return true; // only the first one
        return totalUpper ? word.size() == totalUpper : true;
    }
};