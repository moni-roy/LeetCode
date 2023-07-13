class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if (len(nums) == 1):
            return nums[0]
        
        def go(num):
            last, now = 0, 0
            for n in num:
                last, now = now, max(last + n, now)
            return max(last, now)
        return max(go(nums[1:]), go(nums[:-1]))
    