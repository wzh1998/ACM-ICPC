/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-03 21:43:15
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-03 22:55:41
*/

class Solution {
    public int findPivotIndex(int[] nums, int left, int right) {
		
		int mid = left + (right-left) / 2;
		if(nums.length == 1)
			return 0;
		else if(right-left == 1)
			return left;
		else if(nums[mid] > nums[right]) 
			return findPivotIndex(nums, mid, right);
		else
			return findPivotIndex(nums, left, mid);
	}
	
	public int binarySearch(int[] nums, int left, int right, int target) {
		int mid = left + (right-left) / 2;
		if(left > right) return -1;
		
		if(nums[mid] == target) 
			return mid;
		
		else if(nums[mid] > target) 
			return binarySearch(nums, left, mid-1, target);
		else
			return binarySearch(nums, mid+1, right, target);
	}
	
	public int search(int[] nums, int target) {
		if(nums.length == 0) return -1;
		
        int pivotIndex = findPivotIndex(nums, 0, nums.length-1);
        int resultLeft = binarySearch(nums, 0, pivotIndex, target);
        int resultRight = binarySearch(nums, pivotIndex+1, nums.length-1, target);
        
        if(resultLeft != -1) return resultLeft;
        else if(resultRight != -1) return resultRight;
        else return -1;
        	
    }
}