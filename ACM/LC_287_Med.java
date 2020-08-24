/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-24 20:55:38
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-24 20:56:02
*/

// 解题思路：龟兔算法，二刷前补充证明

class Solution {
    public int findDuplicate(int[] nums) {
		int rabbit = nums[0];
		int turtle = nums[0];

        while(true) {
        	rabbit = nums[nums[rabbit]];
        	turtle = nums[turtle];
        	if(rabbit == turtle) break;
        }
        turtle = nums[0];
        while(rabbit != turtle) {
        	rabbit = nums[rabbit];
        	turtle = nums[turtle];
        }
        return turtle;
    }
}