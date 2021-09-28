// 1D DP
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int sum = 0;
        
        for(int stone : stones) {
            sum += stone;
        }
        
        int[] dp = new int[sum / 2 + 1];
        
        // initialisation
        for(int j = stones[0]; j <= sum / 2; j++) {
            dp[j] = stones[0];
        }
        // iteration
        for(int i = 1; i < stones.length; i++) {
            for(int j = sum / 2; j >= 1; j--) {
                if(j < stones[i]) continue;
                else dp[j] = Math.max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        
        return sum - 2 * dp[sum / 2];
    }
}


// 2D DP
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int sum = 0;
        
        for(int stone : stones) {
            sum += stone;
        }
        
        int[][] dp = new int[stones.length][sum / 2 + 1];
        
        // initialisation
        for(int j = stones[0]; j <= sum / 2; j++) {
            dp[0][j] = stones[0];
        }
        // iteration
        for(int i = 1; i < stones.length; i++) {
            for(int j = 1; j <= sum / 2; j++) {
                if(j < stones[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            }
        }
        
        return sum - 2 * dp[stones.length - 1][sum / 2];
    }
}