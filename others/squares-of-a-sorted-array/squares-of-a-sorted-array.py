class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        ans = [n*n for n in nums]
        # print (ans)
        return sorted(ans)