class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> exist(26, false);
        for(auto c : sentence) {
            exist[c - 'a'] = true;
        }
        for(auto b : exist) {
            if(!b) return false;
        }
        return true;
    }
};