class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> pairCount;
        int ans = 0;
        for (auto word : words) {
            string s = word;
            reverse(s.begin(), s.end());
            if(pairCount[s] > 0) {
                ans += 4;
                pairCount[s] -= 1;
            } else {
                pairCount[word] += 1;
            }
        }
        for (auto &pair : pairCount) {
            if(pair.second > 0 && pair.first[0] == pair.first[1]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};