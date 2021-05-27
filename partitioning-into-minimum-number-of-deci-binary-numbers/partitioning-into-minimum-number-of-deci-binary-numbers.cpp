class Solution {
public:
    int minPartitions(string n) {
        char ans = '0';
        for(auto c: n) {
            ans = max(c, ans);
        }
        return (ans - '0');
    }
};