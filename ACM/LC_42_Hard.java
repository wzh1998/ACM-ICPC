/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-07-29 15:07:45
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-07-29 15:13:09
*/

class Solution {
    public int trap(int[] height) {
        int[] max_left = new int[100000];
        int[] max_right = new int[100000];
        int area = 0;
        
        if(height.length > 0) {
            max_left[0] = height[0];
            max_right[height.length-1] = height[height.length-1];
        }
        
        for(int i = 1; i < height.length; i++) {
            max_left[i] = (max_left[i-1] > height[i]) ? max_left[i-1] : height[i];
        }
        
        for(int i = height.length-2; i >= 0; i--) {
            max_right[i] = (max_right[i+1] > height[i]) ? max_right[i+1] : height[i];
        }
        
        for(int i = 1; i < height.length-1; i++) {
            area += Math.min(max_left[i], max_right[i]) - height[i];
        }
        return area;
    }
}