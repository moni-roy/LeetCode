class Solution {
public:
    int countOdds(int low, int high) {
        int dif = high - low + 1;
        if(dif & 1) {
            if(low & 1) dif += 2;
        }
        return dif/2;
    }
};