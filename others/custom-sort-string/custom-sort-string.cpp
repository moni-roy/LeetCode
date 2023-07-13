class Solution {
public:
    string customSortString(string order, string str) {
        map<char, int> cnt;
        for(auto c: str) cnt[c]++;
        string ret = "";
        for(auto c: order) {
            int n = cnt[c];
            while(n--) {
                ret += c;
            }
            cnt[c] = 0;
        }
        for(auto c: str) {
            int n = cnt[c];
            while(n--) {
                ret += c;
            }
            cnt[c] = 0;
        }
        return ret;
        
    }
};