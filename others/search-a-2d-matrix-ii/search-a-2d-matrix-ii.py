class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        r, c, l = 0, len(matrix[0])-1, len(matrix)
        
        while c>=0 and r < l:
            if matrix[r][c] == target:
                return True
            if matrix[r][c] > target:
                c -= 1
            else:
                r += 1
            
        return False