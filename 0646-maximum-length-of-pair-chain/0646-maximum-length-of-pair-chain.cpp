class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        int cnt = 0, cur = INT_MIN;
        for (auto pair: pairs) {
            if (pair[0] > cur) {
                cnt ++;
                cur = pair[1];
            }
        }
        return cnt;
    }
};