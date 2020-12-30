/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-02 17:53:30
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-12-30 00:28:50
*/

// Modified
class Solution {
    public int maxSubArray(int[] nums) {
        int result = nums[0];
        int currentMax = nums[0];
                
        for(int i = 1; i < nums.length; i++) {
                if(currentMax + nums[i] > nums[i]) 
                        currentMax += nums[i];
                else 
                        currentMax = nums[i];
                
                result = Math.max(result, currentMax);
        }
        
        return result;
    }
}

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
