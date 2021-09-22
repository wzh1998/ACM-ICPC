/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-09-23 00:12:10
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-23 00:12:13
*/
class Solution {
    public void moveZeroes(int[] nums) {
        int insertPos = 0;
        for(int num: nums) {
            if(num != 0) nums[insertPos++] = num;
        }
        while(insertPos < nums.length)
            nums[insertPos++] = 0;
    }
}