/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-22 23:17:27
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-22 23:17:31
*/

class Solution {
        public int findPeakElement(int[] nums) {
		int left = 0;
		int right = nums.length - 1;
		while(left < right) {
			int mid1 = left + ((right - left) >> 1);
			int mid2 = mid1 + 1;
			if(nums[mid1] < nums[mid2])
				left = mid2;
			else if(nums[mid1] > nums[mid2])
				right = mid1;
		}
		
		return left;
    }
}