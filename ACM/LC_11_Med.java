/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-16 20:35:38
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-16 20:35:40
*/
class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int result = 0;
        
        while(left < right) {
        	result = Math.max(result, (right - left) * Math.min(height[left], height[right]));
        	if(height[left] < height[right])
        		left++;
        	else
        		right--;
        }
        
        return result;
    }
}