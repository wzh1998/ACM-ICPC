/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-09 16:56:51
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-09 16:56:55
*/

class Solution {
    public boolean isMatch(String str, String pattern) {
        int s = 0;
        int p = 0;
        
        // Indicates character mached BEFORE this index
        int match = 0;
        int starIndex = -1;
        
        while(s < str.length()) {
        	if(p < pattern.length() && (pattern.charAt(p) == str.charAt(s) || pattern.charAt(p) == '?')) {
        		s++;
        		p++;
        	}
        	else if(p < pattern.length() && pattern.charAt(p) == '*') {
        		starIndex = p;
        		match = s;
        		p++;
        	}
        	else if(starIndex != -1) {
        		match++;
        		s = match;
        		p = starIndex + 1;
        	}
        	else return false;
        }
        
        // 能出上个循环就说明str==pattern或者是后者的子集，现在要排除str=pattern*
    	while(p < pattern.length()) {
    		if(pattern.charAt(p) == '*') p++;
    		else break;
    	}
    	// 剩下的只有可能是str是pattern真子集，即pattern结尾包含非*的多余字符
        return (p == pattern.length());
	}
}