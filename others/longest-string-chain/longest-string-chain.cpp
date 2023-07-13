class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        
        sort(words.begin(), words.end(), [](string w1, string w2) {
           return w1.size() < w2.size(); 
        });
        
        int ans = 1;
        
        for(auto word: words) {
            int mx = 1;
            for(int i = 0; i<word.size(); i++) {
                string pre = word.substr(0, i) + word.substr(i+1);
                
                if(dp.find(pre) != dp.end()) {
                    mx = max(mx, dp[pre] + 1);
                }
            }
            dp[word] = mx;
            ans = max(ans, mx);
        }
        return ans;
    }
};