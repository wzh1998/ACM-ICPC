// compressed to 1D dp array
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 != 0) return false;
        
        int[] dp = new int[sum / 2 + 1];
        
        for(int j = nums[0]; j <= sum / 2; j++) {
            dp[j] = nums[0];
        }
        for(int i = 1; i < nums.length; i++) {
            for(int j = sum / 2; j >= 1; j--) {
                if(j < nums[i]) continue;
                else dp[j] = Math.max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        
        return dp[sum / 2] == sum / 2;
    }
}


// 2D dp array
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 != 0) return false;
        
        int[][] dp = new int[nums.length][sum / 2 + 1];
        for(int j = nums[0]; j <= sum / 2; j++) {
            dp[0][j] = nums[0];
        }
        
        for(int i = 1; i < nums.length; i++) {
            for(int j = 1; j <= sum / 2; j++) {
                if(j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }
        
        return dp[nums.length - 1][sum / 2] == sum / 2;
    }
}