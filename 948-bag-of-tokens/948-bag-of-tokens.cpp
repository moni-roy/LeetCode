class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int left = 0, right = n - 1;
        int score = 0;
        int res = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score++;
                left++;
                res = max(res, score);
            }
            else if (score > 0) {
                power += tokens[right];
                score--;
                right--;
            }
            else break;
        }
        return res;
    }
};