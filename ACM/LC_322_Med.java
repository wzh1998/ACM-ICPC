/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-18 16:47:26
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-18 17:08:22
*/

class Solution {
    public int coinChange(int[] coins, int amount) {
		int[] dp = new int[amount + 1];
		dp[0] = 0;
		
		for(int i = 1; i < dp.length; i++) {
			dp[i] = 1 << 31 - 1;
		}
		
        for(int i = 0; i < dp.length; i++) {
        	for(int j = 0; j < coins.length; j++) {
        		if(i + coins[j] <= amount && i + coins[j] > 0) 
        			dp[i + coins[j]] = Math.min(dp[i] + 1, dp[i + coins[j]]);
        	}
        }
        
        return (dp[amount] != 1 << 31 - 1) ? dp[amount] : -1;
    }
}