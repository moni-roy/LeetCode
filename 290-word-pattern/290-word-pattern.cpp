class Solution {
public:
    bool wordPattern(string pattern, string s) {
        return wordPatternUsingMap(pattern, s);
    }
private:
    bool wordPatternUsingMap(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream iss(s);
        string word;
        int index = 0;
        while (iss >> word) {
            if (charToWord.find(pattern[index]) == charToWord.end()) {
                if (wordToChar.find(word) != wordToChar.end()) {
                    return false;
                }
                charToWord[pattern[index]] = word;
                wordToChar[word] = pattern[index];
            } else if (charToWord[pattern[index]] != word) {
                return false;
            }
            index++;
        }
        return index == pattern.size();
    }
};