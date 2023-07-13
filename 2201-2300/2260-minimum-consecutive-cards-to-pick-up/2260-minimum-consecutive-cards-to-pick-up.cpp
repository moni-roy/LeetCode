class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mapIndex;

        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            if(mapIndex.find(cards[i]) != mapIndex.end()) {
                ans = min(ans, i - mapIndex[cards[i]] + 1);
            }
            mapIndex[cards[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};