class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int left = 0, right = s.size() - 1;
        int count = 0;
        while (left < right) {
            int l = left, r = right;
            while (s[l] != s[r]) r--;
            if (l == r) {
                swap(s[r], s[r + 1]);
                count ++;
                continue;
            }
            else {
                while(r < right) {
                    swap(s[r], s[r + 1]);
                    r++;
                    count ++;
                }
            }
            left++, right--;
        }
        return count;
    }
};