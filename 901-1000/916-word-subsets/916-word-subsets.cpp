class Solution {
public:
    vector<int> count(string s) {
        vector<int> ret(26);
        for(auto c: s) {
            ret[c-'a'] ++;
        }
        return ret;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> bc(26);
        for (auto b: B) {
            vector<int> rt = count(b);
            for (int i = 0; i < 26; i ++) {
                bc[i] = max(bc[i], rt[i]);
            }
        }
        
        vector<string> ret;
        for (auto a: A) {
            vector<int> rt = count(a);
            int f=1;
            for (int i = 0; i < 26; i++){
                if (rt[i] < bc[i]){
                    f = 0;
                    break;
                }
            }
            if (f) ret.push_back(a);
        }
        return ret;
    }
};