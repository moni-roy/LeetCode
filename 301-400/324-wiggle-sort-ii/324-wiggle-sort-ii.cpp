class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        auto getIdx = [] (int i, int n) {
            return (1 + 2 * i) % (n | 1);
        };

        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[getIdx(j, n)] > mid)
                swap(nums[getIdx(j++, n)], nums[getIdx(i++, n)]);
            else if (nums[getIdx(j, n)] < mid)
                swap(nums[getIdx(j, n)], nums[getIdx(k--, n)]);
            else
                j++;
        }
  }
};