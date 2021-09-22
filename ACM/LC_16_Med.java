/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-09-22 23:37:02
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-22 23:37:06
*/
class Solution {
    
    
    public int threeSumClosest(int[] nums, int target) {
        int diff = Integer.MAX_VALUE;
        
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length; i++) {
            int left = i + 1;
            int right = nums.length - 1;
            
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(Math.abs(target - sum) <= Math.abs(diff)) 
                    diff = target - sum;
                if(sum <= target) 
                    left++;
                else 
                    right--;
                
            }
        }
        
        return target - diff;
    }
}