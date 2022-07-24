class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int n = ranks.size();
        vector<int> rank_count(14, 0);
        vector<int> suit_count(4, 0);
        for (int i = 0; i < n; ++i) {
            ++rank_count[ranks[i]];
            ++suit_count[suits[i]-'a'];
        }
        for (int i = 0; i < 4; ++i) {
            if (suit_count[i] == 5) return "Flush";
           }
        for (int i = 0; i < 14; ++i) {
            if (rank_count[i] >= 3) return "Three of a Kind";
        }
        for (int i = 0; i < 14; ++i) {
            if (rank_count[i] == 2) return "Pair";
        }
        return "High Card";
    }
};