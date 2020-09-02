/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-02 17:53:30
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-02 20:21:15
*/

// DP
public int maxSubArray(int[] nums) {
		if(nums.length == 0) return 0;
		
        int[] dp = new int[nums.length];
        int result = nums[0];
        
        dp[0] = nums[0];
        for(int i = 0; i < nums.length - 1; i++) {
        	dp[i + 1] = Math.max(dp[i] + nums[i + 1], nums[i + 1]);
        	if(dp[i + 1] > result) result = dp[i + 1];
        }
        return result;
}

// Divide and Conquer
