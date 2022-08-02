public class Solution {
    
    /* Solution 2: BS */
    public int kthSmallest(int[][] matrix, int k) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int lo = matrix[0][0], hi = matrix[rows - 1][cols - 1] + 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int smaller = 0,  j = cols - 1;
        
            for(int i = 0; i < rows; i++) {
                
                while(j >= 0 && matrix[i][j] > mid) j--; // <-- find the index in this row
                smaller += (j + 1); // <-- (0, j) are smaller
            }
            
            if(smaller < k) lo = mid + 1; // <-- need to go for greater elements
            else hi = mid; // <-- look for smaller elements
        }
        
        return lo;
    }
    
    /* Solution 1: using min heap */
    public int kthSmallestPQ(int[][] matrix, int k) {
        int n = matrix.length;
        PriorityQueue<Cell> pq = new PriorityQueue<>(new Comparator<Cell>(){
            public int compare(Cell o1, Cell o2) {
                return o1.val-o2.val;
            }
        });
        
        for(int j = 0; j <= n-1; j++) pq.add(new Cell(j, matrix[0][j]));
        for(int i = 0; i < k-1; i++) {
            Cell t = pq.poll();
            int x = t.index/n;
            int y = t.index%n;
            if(x == n-1) continue;
            pq.add(new Cell(((x+1)*n)+y, matrix[x+1][y]));
        }
        
        return pq.poll().val;
    }
    
    class Cell{
        int index;
        int val;
        Cell(int i, int val){
            this.index = i;
            this.val = val;
        }
    }
}