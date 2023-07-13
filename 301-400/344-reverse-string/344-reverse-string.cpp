class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int left = 0, right = len - 1; left < right; left++, right--) {
            swap(s[left], s[right]);
        }
    }
};