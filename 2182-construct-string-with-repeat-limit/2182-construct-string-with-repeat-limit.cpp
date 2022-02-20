class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string res;
        while(true) {
            // get max char
            int maxChar = -1;
            int maxCount = 0;
            for(int i = 25; i >= 0; i--) {
                if(count[i]) {
                    maxChar = i;
                    maxCount = count[i];
                    count[i] = 0;
                    break;
                }
            }
            if(maxChar == -1) {
                break;
            }
            while(maxCount) {
                res.append(min(repeatLimit, maxCount), maxChar + 'a');
                maxCount -= min(repeatLimit, maxCount);
                if(maxCount) {
                    // get max char
                    int maxChar2 = -1;
                    for (int i = 25; i >= 0; i--) {
                        if (count[i]) {
                            maxChar2 = i;
                            break;
                        }
                    }
                    if (maxChar2 == -1) {
                        break;
                    }
                    res.append(1, maxChar2 + 'a');
                    count[maxChar2]--;
                }
            }
        }
        return res;
    }
};