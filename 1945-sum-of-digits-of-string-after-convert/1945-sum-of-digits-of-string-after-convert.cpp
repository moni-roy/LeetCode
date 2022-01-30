class Solution {
public:
    int getLucky(string s, int k) {
        return usingGreedy(s, k);
    }
private:
    int usingGreedy(string s, int k) {
        int num = 0;
        for(auto c: s) {
            int t = c-'a' + 1;
            while(t) {
                num += t % 10;
                t /= 10;
            }
        }
        while(k > 1) {
            int t = num;
            num = 0;
            while(t) {
                num += t % 10;
                t /= 10;
            }
            k--;
        }
        return num;
    }
};