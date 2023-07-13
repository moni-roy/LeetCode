class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector <string> res;
        string sb = "";
        long long now = 0;
        for(int i = 0; i < num.size(); i++) {
            sb += num[i];
            now = now*10 + (num[i]-'0');
            if (to_string(now).size() != sb.size()) continue;
            dfs(i+1, now, now, sb, "*", target, num, res);
        }
        return res;
    }
    
    void dfs(int pos, long long current, long long prev, string exp, string preOp, long long target, string &num, vector<string> &res) {
        if(pos == num.size()) {
            if(current == target) {
                res.push_back(exp);
            }
            return ;
        }
        
        string sb = "";
        long long now = 0;
        for(int i = pos; i < num.size(); i++) {
            sb += num[i];
            now = now *10 + (num[i] -'0');
            if (to_string(now).size() != sb.size()) continue;
            dfs(i+1, current + now, now, exp + "+" + sb, "+", target, num, res);
            dfs(i+1, current - now, now, exp + "-" + sb, "-", target, num, res);
            dfs(i+1, (preOp == "+") ? (current - prev + prev*now):((preOp == "-")?(current + prev - prev*now): prev*now), prev*now, exp + "*" + sb, preOp, target, num, res);   
        }
        return ;
    }
};