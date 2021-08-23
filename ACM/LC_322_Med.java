/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-18 16:47:26
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-23 16:43:26
*/

// My 2021 solution
class Solution {
    public int coinChange(int[] coins, int amount) {
        if(amount == 0) return 0;
        int[] dp = new int[amount + 1];
        
        // Initialisation
        for(int i = 0; i < dp.length; i++)
            dp[i] = -1;
        // Dynamic programming
        for(int i = 0; i <= amount; i++) {
            
            for(int j = 0; j < coins.length; j++) {
                int currentVal = coins[j];
                
                if(i < currentVal) continue;
                
                if(i == currentVal)
                    dp[i] = 1;
                else if(dp[i - currentVal] != -1)
                    dp[i] = (dp[i] == -1) ? (dp[i - currentVal] + 1) : Math.min(dp[i], dp[i - currentVal] + 1);
                
            }
        }
        
        return dp[amount];
    }
}

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