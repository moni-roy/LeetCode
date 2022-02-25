public class Solution {
    /* Solution: no extra space */
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
    
    /* Solution: extra space */
    public int[] productExceptSelfExtra(int[] nums) {
        if(nums.length==0) return new int[0];
        
        int len = nums.length;
        int[] res = new int[len];
        int[] left = new int[len];
        int[] right = new int[len];
        //calculate left and right
        for(int i=0,j=len-1;i<len;i++,j--){
        	if(i==0){
        		left[i] = 1;
        		right[j] = 1;
        	}
        	else{
        		left[i] = left[i-1] * nums[i-1];
        		right[j] = right[j+1] * nums[j+1];
        	}
        }
        //calculate result
        for(int i=0;i<len;i++){
        	res[i] = left[i] * right[i];
        }
        return res;
    }
}