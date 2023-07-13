class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<bitset<26>> mp(n, 0);
        int ans = 0;
        for(int i = 0; i<n ; i++) {
            for(auto c: words[i]) {
                mp[i][c-'a'] = 1;
            }
            for(int j = 0 ; j<i; j++) {
                if(isOk(mp[i], mp[j])) {
                    ans = ans<(words[i].size()*words[j].size())?(words[i].size()*words[j].size()):ans;
                    // ans = max(ans, (words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
    bool isOk(bitset<26> &x, bitset<26> &y) {
        for(int i = 0; i<26;i++) {
            if(x[i] && y[i]) return false;
        }
        return true;
    }
};