class Solution {
public:
    bool isPossible(string &s, string &t, int p) {
        int all = 0;
        for (int i = 0; i < s.size(); i++){
            if(t[p + i] =='?') all += 1;
            if(s[i] != t[p + i] && t[p + i] != '?') return false;
        }
        if(all == s.size()) return false;
        return true;
    }
    
    int doReplace(int l, int p, string &t) {
       int done = 0;
        for (int i = 0; i < l; i++) {
            if(t[i + p] != '?') {
                t[i + p] = '?';
                done ++;
            }
        }
        return done;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int size = target.size();
        vector<int> v(size), ans;
        int done = 0;
        while (done != size) {
            int possible = 0;
            for (int i = 0; i <= size - stamp.size(); i++) {
                if (v[i] == 0 && isPossible(stamp, target, i)) {
                    done += doReplace(stamp.size(), i, target);
                    v[i] = 1;
                    possible = 1;
                    ans.push_back(i);
                }
            }
            if(!possible) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};