/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-21 09:45:18
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-21 10:06:05
*/

class Solution {
    public int lowerBound(int[] nums, int left, int right, int target) {
		int mid;
		while(left < right) {
			mid = left + ((right - left) >> 1);
			if(nums[mid] < target) 
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
	
	public int[] searchRange(int[] nums, int target) {
		
		if(nums.length == 0) 
			return new int[] {-1, -1};
		
        int lowerIndex = lowerBound(nums, 0, nums.length, target);
        
        if(lowerIndex == nums.length || nums[lowerIndex] != target)
        	return new int[] {-1, -1};
        
        return new int[] {lowerIndex, lowerBound(nums, lowerIndex, nums.length, target + 1) - 1};
    }
}