class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> s;
        for (auto& word : words) {
            string morse_word;
            for (auto& c : word) {
                morse_word += morse[c - 'a'];
            }
            s.insert(morse_word);
        }
        return s.size();
    }
};