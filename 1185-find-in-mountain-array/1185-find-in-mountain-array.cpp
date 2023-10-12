/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();

        int low = 1, high = len - 2;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int l = 0, h = low;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (mountainArr.get(m) < target) l = m + 1;
            else h = m;
        }
        if (mountainArr.get(l) == target) return l;
        
        l = low + 1;
        h = len - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (mountainArr.get(m) > target) l = m + 1;
            else h = m;
        }
        if (mountainArr.get(l) == target) return l;

        return -1;
    }
};