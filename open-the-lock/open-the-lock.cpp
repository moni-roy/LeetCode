class Solution {
public:
    int openLock(vector<string>& dd, string target) {
        unordered_set<string> st(dd.begin(), dd.end());
        map<string, int> mp;
        queue<string> q;
        
        string in = "0000";
        if(st.find(in)!=st.end()) return -1;
        
        q.push(in);
        mp[in] = 1;
        
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if(s == target) return mp[s]-1;
            vector<string> v = move(s);
            for(auto ss: v) {
                if(st.find(ss) == st.end() && mp[ss] == 0) {
                    mp[ss] = mp[s] + 1;
                    q.push(ss);
                }
            }
        }
        return -1;
    }
    
    vector<string> move(string s) {
        vector<string> ret;
        for(int i = 0; i< 4; i++) {
            string ss = s;
            // forward
            int t = (s[i] - '0' + 1)%10;
            ss[i] = t + '0';
            ret.push_back(ss);
            // backward
            t = (s[i] - '0' - 1 + 10)%10;
            ss[i] = t + '0';
            ret.push_back(ss);
        }
        
        return ret;
    }
};