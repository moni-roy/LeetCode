class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n*2, "", ans);
        return ans;
    }
    
    void dfs(int p, string s, vector<string> &ans) {
        if(p <= 0){
            if(isOk(s)) ans.push_back(s);
            return;
        }
        dfs(p-1, s +"(", ans);
        dfs(p-1, s+")", ans);
    }
    
    bool isOk(string s) {
        stack<char> st;
        for(int i = 0; s[i]; i++) {
            if(s[i] == ')'){
                if(st.empty()) return false;
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
    
};