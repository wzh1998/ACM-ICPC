/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-07-31 15:28:11
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-07-31 16:04:10
*/

class Solution {
    public void sortColors(int[] nums) {
       
		int indexZero = 0;
		int indexTwo = nums.length - 1;

		for(int i = 0; i <= indexTwo; i++) {
			if(nums[i] == 0) {
				nums[i] = nums[indexZero];
				nums[indexZero] = 0;
				indexZero++;
			}
			else if(nums[i] == 2) {
				nums[i] = nums[indexTwo];
				nums[indexTwo] = 2;
				indexTwo--;
                i--;
			}
		}
	}
}