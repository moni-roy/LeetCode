class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int odd_sum = 0;
        int even_sum = 0;
        for(int i = 0; i < n; i++) {
            if(position[i]&1) {
                odd_sum += 1;
            }
            else even_sum += 1;
        }
        return min(even_sum, odd_sum);
    }
};