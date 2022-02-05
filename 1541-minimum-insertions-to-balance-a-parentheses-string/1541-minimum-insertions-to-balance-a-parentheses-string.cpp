class Solution {
public:
    int minInsertions(string s) {
        return usingCount(s);
    }
private:
    int usingCount(string s) {
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(') {
                if (close % 2 > 0) {
                    open++;
                    close--;
                } 
                close += 2;
            } else {
                close --;
                if (close < 0) {
                    open++;
                    close += 2;
                }
            }
        }
        return open + close;
    }
};