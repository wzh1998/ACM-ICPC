/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-01 20:34:08
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-01 20:38:17
*/

// Solution 1 - General Quick Sort
class Solution {
    public static void quickSort(int[]nums, int left, int right) {
		if(nums.length == 0 || left >= right) return;
		
		int pivot = nums[left];
		int i, j;
		for(i = left, j = right; i < j;) {
			while(i < j && nums[j] > pivot) j--;
			if(i < j) nums[i++] = nums[j];
			
			while(i < j && nums[i] < pivot) i++;
			if(i < j) nums[j--] = nums[i];
		}
		nums[i] = pivot;
		
		quickSort(nums, left, i - 1);
		quickSort(nums, i + 1, right);
	}
	
	public int findKthLargest(int[] nums, int k) {
        quickSort(nums, 0, nums.length - 1);
        return nums[nums.length - k];
    }
}