/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-12-30 23:34:36
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-12-30 23:34:44
*/
class Solution {
    public void reverseString(char[] s) {
        int left = 0;
        int right = s.length - 1;
        while(left < right) {
        	char tmp = s[left];
        	s[left] = s[right];
        	s[right] = tmp;
        	left++;
        	right--;
        }
    }
}
