class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balon";
        int fr[26] = {0};
        for(int i = 0; i < text.size(); i++) {
            fr[text[i] - 'a'] ++;
        }
        fr['l'-'a'] /= 2;
        fr['o'-'a'] /= 2;
        int ans = INT_MAX;
        for(int i = 0; i <5; i++) {
            ans = min(ans, fr[s[i] - 'a']);
        }
        return ans;
    }
};