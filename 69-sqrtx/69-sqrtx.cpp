class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;
        while(low < high) {
            long long mid = low + (high - low) / 2;
            
            if (mid * mid == x) return mid;
            if (mid * mid > x) high = mid - 1;
            else {
                if ( (mid + 1) * (mid + 1) > x) return mid;
                low = mid + 1;
            }
        }
        return low;
    }
};