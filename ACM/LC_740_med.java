/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-08-08 12:55:38
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-08 13:07:38
*/

// Optimised solution
class Solution {
    public int deleteAndEarn(int[] nums) {
        int[] sum = new int[10001];
        
        for(int i = 0; i < nums.length; i++)
            sum[nums[i]] += nums[i];
        
        for(int i = 2;i < sum.length; i++) 
            sum[i] = Math.max(sum[i - 1], sum[i - 2] + sum[i]);
        
        return sum[sum.length - 1];
    }
}


// Original solution
class Solution {
    public int deleteAndEarn(int[] nums) {
        Arrays.sort(nums);
        int[] uniqueNums = new int[nums.length];
        int[] uniqueSums = new int[nums.length];
        
        int count = 0;
        for(int i = 0; i < nums.length; i++) {
            if(i != 0 && nums[i] != nums[i - 1]) count++;
            uniqueNums[count] = nums[i];
            uniqueSums[count] += nums[i];
        }
        
        int[] dp = new int[count + 1];
        dp[0] = uniqueSums[0];
        
        for(int i = 1; i <= count; i++) {
            if(uniqueNums[i] != uniqueNums[i - 1] + 1) 
                dp[i] = dp[i - 1] + uniqueSums[i];
            else
                dp[i] = Math.max(dp[i - 1], (i >= 2 ? dp[i - 2] : 0) + uniqueSums[i]);
        }
        
        return dp[count];
    }
}