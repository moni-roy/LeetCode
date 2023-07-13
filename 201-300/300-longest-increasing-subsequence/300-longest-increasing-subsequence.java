class Solution {
    
    /* sol: binary search */
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
        if(len < 2) return len;
        
        int max = 0;
        int[] sarr = new int[len];
        /* now fill up with max values, otherwise BS will not return proper idx */
        Arrays.fill(sarr, Integer.MAX_VALUE);
        for(int num: nums){
            int idx = Arrays.binarySearch(sarr, num);
            if(idx < 0) idx = -idx-1;
            sarr[idx] = num;
            max = Math.max(max, 1+idx);
        }
        
        return max;
    }
    
    /* sol: o(n^2) */
    public int lengthOfLISDP(int[] nums) {
        int len = nums.length;
        if(len < 2) return len;
        
        int[] dp = new int[len];
        dp[0] = 1;
        for(int i=1; i<len; i++){
            dp[i] = 1;
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j]){
                    dp[i] = Math.max(dp[i], 1+dp[j]);
                }
            }
        }
        
        int max = 1;
        for(int d: dp) max = Math.max(max, d);
        return max;
    }
}