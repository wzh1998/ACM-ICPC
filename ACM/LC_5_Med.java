/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-12-22 22:26:27
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-12-22 22:27:03
*/

class Solution {
    int maxLen = 0;
	int startIdx = 0;
	
	public String longestPalindrome(String s) {
		
		if(s.length() < 2) return s;
		
        for(int i = 0; i < s.length() - 1; i++) {
        	findPalindrom(s, i, i);
        	findPalindrom(s, i, i + 1);
        }
        return s.substring(startIdx, startIdx + maxLen);
    }
	public void findPalindrom(String s, int low, int high) {
		while(low >= 0 && high < s.length() && s.charAt(low) == s.charAt(high)) {
			low--;
			high++;
		}
		if(high - low - 1 > maxLen) {
			maxLen = high - low - 1;
			startIdx = low + 1;
		}
	}
}