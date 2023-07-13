public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0) return false;
        
        int row = matrix.length;
        int col = matrix[0].length;
        
        int x = 0,y = col - 1;
        while(x < row && y >= 0){
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] < target){
                x++;
            }
            else y--;
        }
        return false;
    }
}