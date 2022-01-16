class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(maxDoubles-- && target > 1) {
            if(target & 1) ans++;
            target /= 2;
            ans ++;
        }
        return ans + target - 1;
    }
};