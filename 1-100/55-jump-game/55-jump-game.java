public class Solution {
    public boolean canJump(int[] A) {
		if(A.length==0) return false;		
		int len = A.length;
		
		int max_reach = 0;
		for(int i=0;i<len;i++){
			if(max_reach < i) return false;
			max_reach = Math.max(max_reach, i + A[i]);
		}
		return true;
	}
}