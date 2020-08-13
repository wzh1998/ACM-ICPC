/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-14 00:00:58
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-14 00:01:11
*/

class Solution {
    public int numSquares(int n) {
        
		int[] dp = new int[n+1];
		
		for(int i = 1; i <= n; i++)
			dp[i] = 1 << 31 - 1;
		
		dp[0] = 0;
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j * j <= i; j++) {
				if(dp[i] > dp[i-j*j] + 1) 
					dp[i] = dp[i-j*j] + 1;
			}
		}
		
		return dp[n];
    }
}