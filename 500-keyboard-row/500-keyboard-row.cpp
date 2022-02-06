class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string keyboards[3] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> res;
        for (auto& word : words) {
            bool flag = true;
            for (int i = 0; i < 3; ++i) {
                if (find(keyboards[i].begin(), keyboards[i].end(), word[0]) != keyboards[i].end()) {
                    for (int j = 1; j < word.size(); ++j) {
                        if (find(keyboards[i].begin(), keyboards[i].end(), word[j]) == keyboards[i].end()) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        res.push_back(word);
                        break;
                    }
                }
            }
        }
        return res;
    }
};