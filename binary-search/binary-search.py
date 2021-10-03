class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = bisect.bisect_left(nums, target, lo=0, hi=len(nums))
        return -1 if l >= len(nums) or nums[l] != target else l