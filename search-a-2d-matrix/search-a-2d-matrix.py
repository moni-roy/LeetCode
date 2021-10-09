class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for mt in matrix:
            if target in mt:
                return True
        return False