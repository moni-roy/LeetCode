class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 0;
        int left = -1;
        for(int i = 0; i < n; ++i) {
            if(seats[i] == 1) {
                if(left == -1) {
                    ans = max(ans, i);
                } else {
                    ans = max(ans, (i - left) / 2);
                }
                left = i;
            }
        }
        return max(ans, n - 1 - left);
    }
};