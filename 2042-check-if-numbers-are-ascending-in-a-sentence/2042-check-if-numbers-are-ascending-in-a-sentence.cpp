class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        int prev = -1;
        int curr = -1;
        for(auto c : s) {
            if(c >= '0' && c <= '9') {
                curr = (curr == -1 ? 0 : curr) * 10 + (c - '0');
            } else if(curr != -1) {
                // cout<<curr<<" "<<prev<<endl;
                if(prev == -1) {
                    prev = curr;
                } else {
                    if(curr <= prev) {
                        return false;
                    }
                    prev = curr;
                }
                curr = -1;
            }
        }
        if(curr != -1 && curr <= prev) {
            return false;
        }
        return true;
    }
};