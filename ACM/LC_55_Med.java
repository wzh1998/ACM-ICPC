/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-03 17:07:35
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-03 17:07:45
*/

// Greedy
class Solution {
    public boolean canJump(int[] nums) {
        int maxRange = 0;
        for(int i = 0; i < nums.length; i++) {
        	if(i > maxRange) return false;
        	else if(maxRange >= nums.length - 1) return true;
        	// nums[i] + i 为当前距离+能走的步数（即从nums[0]起所能到达的最远距离)
        	maxRange = Math.max(nums[i] + i, maxRange);
        }
        return true;
    }
}