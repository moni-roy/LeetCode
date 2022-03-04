class Solution {
    public int jump2(int[] A) {
        if(A.length==0) return 0;		
		int len = A.length;
		int max_reach = 0, cur_reach = 0, steps = 0;
		for(int i=0;i<len;i++){
			if(max_reach < i) {
                steps ++;
                max_reach = cur_reach;
            }
			cur_reach = Math.max(cur_reach, i + A[i]);
		}
		return steps;
    }
    
    public int jump(int[] A) {
        if(A.length==0) return 0;		
		int len = A.length;
		int max_reach = A[0], cur_reach = 0, steps = 0;
        
		for(int i=1;i<len;){
            for(int j = i; j <= max_reach && j < len; j++) {
                cur_reach = Math.max(cur_reach, j + A[j]);
            }
            steps ++;
            i = max_reach + 1;
            max_reach = cur_reach;
		}
		return steps;
    }
}
