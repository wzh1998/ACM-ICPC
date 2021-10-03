class Solution {
    public int robRange(int[] nums, int startIdx, int endIdx) {
        int[] dp = new int[nums.length];
        dp[startIdx] = nums[startIdx];
        dp[startIdx + 1] = Math.max(nums[startIdx], nums[startIdx + 1]);
        
        for(int i = startIdx + 2; i <= endIdx; i++) 
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        
        
        return dp[endIdx];
    }
    public int rob(int[] nums) {
        if(nums.length < 2) return nums[0];
        else if(nums.length == 2) return Math.max(nums[0], nums[1]);
        
        return Math.max(robRange(nums, 0, nums.length - 2), robRange(nums, 1, nums.length - 1));
    }
}