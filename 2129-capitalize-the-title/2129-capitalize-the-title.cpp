class Solution {
public:
    string capitalizeTitle(string title) {
        string res;
        vector<string> words;
        stringstream ss(title);
        string word;
        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            words.push_back(word);
        }
        for (int i = 0; i < words.size(); ++i) {
            if(words[i].size() > 2) words[i][0] = toupper(words[i][0]);
            if (i == 0) {
                res += words[i];
            } else {
                res += ' ';
                res += words[i];
            }
        }
        return res;
    }
};