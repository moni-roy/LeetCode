class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for(int pen = 0; pen <= total/cost1; pen ++) {
            long long tPencil = (total - pen * cost1) / cost2;
            ans += (tPencil + 1);
        }
        return ans;
    }
};