/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-14 18:34:49
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-14 19:53:15
*/

// UNSOLVED

public boolean isMatch(String str, String pattern) {
		
		if(pattern.equals(".*")) return true;
		
        int s = 0;
        int p = 0;
        int starIndex = -1;
        int match = 0;
        char starChar = '?';
        
        while(s < str.length()) {
        	if(p < pattern.length() && (str.charAt(s) == pattern.charAt(p) || pattern.charAt(p) == '.')) {
        		s++;
        		p++;
        	}
        	
        	else if (p < pattern.length() - 1 && pattern.charAt(p + 1) == '*') {
        		p += 2;
        	}
        	// 至此 * 代表的个数已经排除了是0的可能
        	else if(p < pattern.length() && pattern.charAt(p) == '*') {
        		starIndex = p;
        		match = s;
        		starChar = pattern.charAt(p - 1);
        		p++;
        	}
        	else if(starIndex != -1 && str.charAt(s) == starChar){
        		match++;
        		s = match;
        		p = starIndex + 1;
        	}
        	else 
        		return false;
        }
        return (p == pattern.length());
    }