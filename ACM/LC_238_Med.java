/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-07 23:37:27
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-07 23:37:30
*/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        
        int right = nums[nums.length-1];
        int[] result = new int[nums.length];
        
        if(nums.length == 0) return nums;
        
        result[0] = 1;
        for(int i = 1; i < nums.length; i++) {
            result[i] = result[i-1] * nums[i-1];
        }
        
        for(int i = nums.length - 2; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }
        
        return result;
    }
}