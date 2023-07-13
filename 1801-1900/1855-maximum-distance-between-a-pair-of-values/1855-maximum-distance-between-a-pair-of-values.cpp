class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
		return usingTwoPointers(nums1, nums2);
        return usingBS(nums1, nums2);
    }
private:
	int usingTwoPointers(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		int i = 0, j = 0, max_dist = 0;
		while (i < n1 && j < n2) {
			if (nums1[i] > nums2[j])  {
				i ++;
			} else {
				max_dist = max(max_dist, j - i);
				j ++;
			}
		}
		return max_dist;
	}
    int usingBS(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
		reverse(nums2.begin(), nums2.end());
		int max_dist = 0;
		for (int i = 0; i < n1; ++i) {
			int j = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
			j = n2 - 1 - j;
			if(i <= j) max_dist = max(max_dist, j - i);
		}
		return max_dist;
    }
};