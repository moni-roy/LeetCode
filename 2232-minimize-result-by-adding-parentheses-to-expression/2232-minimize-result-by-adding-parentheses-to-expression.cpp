class Solution {
public:
    string minimizeResult(string expression) {
		int n = expression.size();
		string s1, s2, tm = "";
		for(int i = 0; i < n; i++) {
			if(expression[i] == '+') {
				s1 = tm;
				tm = "";
			}
            else tm += expression[i];
		}
		s2 = tm;
		int total = stoi(s1) + stoi(s2);
		string ans = "(" + s1 + "+" + s2 + ")";
		for(int i = 0; i < s1.size(); i++) {
			for(int j = 0; j < s2.size(); j++) {
				string fs = s1.substr(0, i), ss = s1.substr(i), ts = s2.substr(0, j), tt = s2.substr(j);
                
				int num = stoi(ss);
                if(ts.size() == 0) {
                    num += stoi(tt);
                }
                else {
                    num += stoi(ts);
                }
				if(fs.size()) num *= stoi(fs);
				if(ts.size()) num *= stoi(tt);
				total = min(total, num);
				if(total == num) {
					ans = fs + "(" + ss + "+";
                    if(ts.size() == 0) ans += tt + ")";
                    else ans += ts + ")" + tt;
				}
			}
		}
		return ans;
    }
    int stoi(string s) {
        if(s.size() == 0) return 0;
        stringstream ss(s);
        int t;
        ss >> t;
        return t;
    }
};