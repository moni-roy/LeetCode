class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = 0;
        int step = n - 1;
        int rest = time % step;
        int round = (time + step - 1) / step;
        // cout << rest << " " << round<< endl;

        if (round % 2 == 1) {
            if (rest == 0) ans = n;
            else ans = rest + 1;
        } else {
            if (rest == 0) ans = 1;
            else ans = n - rest;
        }
        return ans;   
    }
};