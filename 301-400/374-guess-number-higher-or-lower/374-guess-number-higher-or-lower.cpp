/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long low = 1, high = n;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int ret = guess(mid);
            if (ret == 0) return mid;
            else if (ret == 1) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};