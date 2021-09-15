class Solution {
public:
    bool is(char c) {
       return (c>='a' && c<='z') || (c >= 'A' && c <= 'Z');
    }
    
    string reverseOnlyLetters(string s) {
        string r = "", sb = "";
        for(int i = 0, j =s.size()-1; i<j;) {
            if(is(s[i]) && is(s[j])) {
                swap(s[i++], s[j--]);
            }
            if(!is(s[i])) i++;
            if(!is(s[j])) j--;
        }
        
        return s;
    }
};