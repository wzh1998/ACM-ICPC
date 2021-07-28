/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-07 23:37:27
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-07-23 17:18:31
*/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] results = new int[len];
        int right = 1;
        
        results[0] = 1;
        
        for(int i = 1; i < len; i++) 
            results[i] = results[i - 1] * nums[i - 1];
        
        for(int i = len - 1; i >= 0; i--) {
            results[i] *= right;
            right *= nums[i];
        }
        
        return results;
    }
}