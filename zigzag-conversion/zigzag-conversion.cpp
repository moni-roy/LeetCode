class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
    	int block = 2*numRows - 2;
    	vector<string> st(numRows, "");
    	for(int i = 0; i < s.size(); i+=block) {
    		for(int j = 0; j<block && i+j < s.size(); j++) {
				if(j>=numRows) {
					int t = numRows-2-j%numRows;
					st[t]+= s[i+j];
				}
				else {
					st[j] += s[i+j];
				}
			}
		}
		string ans = "";
		for(int i = 0; i<numRows; i++) {
			ans += st[i];
		}
    	return ans;	
    }
};

