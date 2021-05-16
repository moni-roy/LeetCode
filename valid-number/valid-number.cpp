class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), i = 0, digits = 0, points = 0;
        
        for(; isspace(s[i]); i++);  
        for(; isspace(s[i]); n--);
        int ii = i;
        // cout<<i<<" "<<n<<endl;
        bool numSeen = false, numSeenAe = true, pointSeen = false, eSeen = false;
        for(;i<n;i++) {
            // cout<<s[i]<<endl;
            if(isdigit(s[i])) {
                numSeen = true;
                numSeenAe = true;
            }
            else if(s[i] == '.') {
                if(pointSeen || eSeen) return false;
                pointSeen = true;
            }
            else if(tolower(s[i]) == 'e') {
                if(!numSeen || eSeen) return false;
                eSeen = true;
                numSeenAe = false;
            }
            else if(s[i] == '+' || s[i] == '-') {
                if(i!=ii && tolower(s[i-1])!='e') return false;
            }else {
                return false;
            }
        }
        return numSeen && numSeenAe;
    }
};