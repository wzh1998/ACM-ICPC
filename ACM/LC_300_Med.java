/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-16 16:47:53
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-16 23:09:21
*/

// Solution 1 - O(n^2)
class Solution {
    public int lengthOfLIS(int[] nums) {
		
		if(nums.length == 0) return 0;
		
		int[] dp = new int[nums.length];
 		int result = 1;
 		
        for(int i = 0; i < nums.length; i++) {
        	dp[i] = 1;
        	for(int j = 0; j < i; j++) {
        		if(nums[j] < nums[i])
        			dp[i] = Math.max(dp[i], dp[j] + 1);
        	}
        	result = Math.max(result, dp[i]);
        }
        return result;
    }
}

// Solution 2 - O(n*logn)
class Solution {
    public int lowerBound(int[]dp, int left, int right, int target) {
        
        int mid;
        
        while(left < right) {
            mid = left + (right - left) / 2;
            
            if(target > dp[mid]) {
                left = mid + 1;
            }
            else if(target <= dp[mid]) {
                right = mid;
            }
        }
        return left;
    }
    
    public int lengthOfLIS(int[] nums) {
        
        if(nums.length == 0) return 0;
        
        int[] dp = new int[nums.length];
        for(int i = 0; i < dp.length; i++) 
            dp[i] = 1 << 31 - 1;
        
        for(int i = 0; i < nums.length; i++) {
            dp[lowerBound(dp, 0, i, nums[i])] = nums[i];
        }
        
        for(int i = dp.length - 1; i >= 0; i--) {
            if(dp[i] != 1 << 31 - 1) return i+1;
        }
        return -1;
    }
}