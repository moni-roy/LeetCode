class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<string, int> target;
        for(auto t: targetWords) {
            sort(t.begin(), t.end());
            target[t]++;
        }
        int ans = 0;
        for(auto s: startWords)  {
            for(char c = 'a'; c <= 'z'; ++c) {
                if(count(s.begin(), s.end(), c)) continue;
                auto t = s + c;
                sort(t.begin(), t.end());
                
                if(target.find(t) != target.end()) {
                    ans += target[t];
                    target.erase(t);
                }
            }
        }
        return ans;
    }
};