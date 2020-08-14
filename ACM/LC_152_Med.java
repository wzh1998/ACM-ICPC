/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-14 22:04:31
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-14 22:04:34
*/

class Solution {
    public int maxProduct(int[] nums) {
        int result = nums[0];
        int dp_max, dp_min;
        dp_max = dp_min = nums[0];
        
        for(int i = 1; i < nums.length; i++) {
        	// 小于等于0确保遇到nums[i]==0的情况时max，min归零
        	// 特殊情况：-1 1 2 0 3 4 -1 3 -100
        	if(nums[i] <= 0) {
        		int temp = dp_max;
        		dp_max = dp_min;
        		dp_min = temp;
//        		负数不能用位操作swap
//        		dp_max = dp_max ^ dp_min;
//        		dp_min = dp_max ^ dp_min;
//        		dp_max = dp_min ^ dp_min;
        	}
        	
        	dp_max = Math.max(dp_max * nums[i], nums[i]);
        	dp_min = Math.min(dp_min * nums[i], nums[i]);
        	
        	result = Math.max(result, dp_max);
        }
        return result;
    }
}