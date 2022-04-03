class Solution {
public:
    int convertTime(string current, string correct) {
        // convert time to minutes
        int c = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int c2 = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int max = 24 * 60;
        if( c2 > c) c %= max;
        
        int diff = c2 - c;
        int ans = diff / 60;
        diff = diff % 60;
        ans += diff / 15;
        diff %= 15;
        ans += diff / 5;
        diff %= 5;
        ans += diff;
        return ans;
    }
};