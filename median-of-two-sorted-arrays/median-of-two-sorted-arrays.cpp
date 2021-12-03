class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2, nums1);
        int k = (n + m + 1) / 2;
        int l = 0, r = n;
        while (l < r) {
            int i = (l + r) / 2;
            int j = k - i;
            if (i < n && nums2[j - 1] > nums1[i]) l = i + 1;
            else r = i;
        }
        int i = l;
        int j = k - l;
        int a = max(i > 0 ? nums1[i - 1] : INT_MIN, j > 0 ? nums2[j - 1] : INT_MIN);
        if ((n + m) % 2 == 1) return a;
        int b = min(i < n ? nums1[i] : INT_MAX, j < m ? nums2[j] : INT_MAX);
        return (a + b) / 2.0;
    }
};