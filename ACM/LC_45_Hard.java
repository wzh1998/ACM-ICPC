/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-03 17:45:32
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-03 17:59:07
*/

// AC solution with condition break, 282ms, still need to improve.
class Solution {
    public int jump(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = 0;
        
        for(int i = 1; i < nums.length; i++) {
        	for(int j = 0; j < i; j++) {
        		if(j + nums[j] >= nums.length - 1)
        			return dp[j] + 1;
        		else if(j + nums[j] >= i) {
        			dp[i] = dp[j] + 1;
        			break;
        		}
        	}
        }
        return dp[nums.length - 1];
    }
}


//DP - O(N^2) - TLE 
class Solution {
    public int jump(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = 0;

        for(int i = 1; i < dp.length; i++) dp[i] = (1 << 31) - 1;
        
        for(int i = 0; i < nums.length; i++) {
        	for(int j = 0; j < i; j++) {
        		if(j + nums[j] >= i) {
        			dp[i] = Math.min(dp[i], dp[j] + 1);
        		}
        	}
        }
        return dp[nums.length - 1];
    }
}
