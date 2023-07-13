class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        int i = 0;
        while (i < n) {
            int len = words[i].size();
            int j = i + 1;
            while (j < n && len + words[j].size() + j - i <= maxWidth) {
                len += words[j].size();
                j++;
            }
            string line = makeLine(words, i, j-1, maxWidth, len);
            res.push_back(line);
            i = j;
        }
        return res;
    }
    string makeLine(vector<string>& words, int i, int j, int maxWidth, int len) {
        string line;
        if (j == i) {
            line = words[i];
            line.append(maxWidth - len, ' ');
        } else if (j == words.size() - 1) {
            line = words[i];
            for (int k = i + 1; k <= j; k++) {
                line.append(" ");
                line.append(words[k]);
                len++;
            }
            line.append(maxWidth - len, ' ');
        } 
        else {
            int n = j - i;
            int space = maxWidth - len;
            int spacePerWord = space / n;
            int extraSpace = space % n;
            for (int k = i; k <= j; k++) {
                line.append(words[k]);
                if (k < j) {
                    line.append(spacePerWord + (k - i < extraSpace ? 1 : 0), ' ');
                }
            }
        }
        return line;
    }
};