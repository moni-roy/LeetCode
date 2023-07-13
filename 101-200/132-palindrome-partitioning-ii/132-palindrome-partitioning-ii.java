public class Solution {
    public int minCut(String s) {
		int len = s.length();
		int[] cut = new int[len];		
		
		boolean[][] dp = new boolean[len][len];
		
		//iterate for each length, from 0 to l, not diagonally. its top down for each len. following way
		//for l=0,1,2. top -> down
		//...
		// ..
		//  .
		for (int l = 0; l < s.length(); l++) {
			cut[l] = l+1;
			char c = s.charAt(l);
			
			for (int i = 0; i <= l; i++) {
				if (i == l)
					dp[i][l] = true;
				else if(i == l - 1){
					if(c==s.charAt(i)) dp[i][l] = true;
					else dp[i][l] = false;
				}
				else{
					if (c==s.charAt(i) && dp[i + 1][l - 1]) dp[i][l] = true;
					else dp[i][l] = false;
				}
				
				if (dp[i][l]) {
					if(i==0) cut[l] = 0; // i==0 means 0 to l fully palindrome, so no cut
					else{
						//takes min from earlier cut and current
						cut[l] = Math.min(cut[l], cut[i-1] + 1);
					}
				}
			}
		}

		return cut[len-1];
	}
    
    /* Sol-2.2: top-down dp using 2d array */
    public int minCutWA(String s) {
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        int[] memo = new int[len];
        return dfs(s, 0, dp, memo, s.length() - 1);
    }

    int dfs(String s, int start, boolean[][] dp, int[] memo, int ret) {
        if (start >= s.length() - 1 || dp[start][s.length()-1] == true) {
            return 0;
        }
        if(memo[start] !=0) return memo[start];
        for (int end = start; end < s.length(); end++) {
            if (s.charAt(start) == s.charAt(end) && 
                (end - start <= 2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                ret = Math.min(ret, 1 + dfs(s, end+1, dp, memo, ret));
            }
        }
        return memo[start] = ret;
    }
}