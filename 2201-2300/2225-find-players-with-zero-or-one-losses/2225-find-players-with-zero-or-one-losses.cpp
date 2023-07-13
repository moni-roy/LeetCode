class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> win, lose;
        for (auto& match : matches) {
            win[match[0]]++;
            lose[match[1]]++;
        }
        vector<int> winner, loser;
        for (auto& p : win) {
            if(lose.find(p.first) == lose.end()) winner.push_back(p.first);
        }
        for (auto& p : lose) {
            if(p.second == 1) loser.push_back(p.first);
        }
        sort(winner.begin(), winner.end());
        sort(loser.begin(), loser.end());
        return {winner, loser};
    }
};