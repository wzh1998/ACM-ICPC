/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-08-26 14:55:42
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-26 14:55:47
*/

public boolean isSelfDescribing(int num) {
		int[] count = new int[10];
		char[] arr = String.valueOf(num).toCharArray();
		
		if(num < 1000 || num > 999999999) 
			return false;
		
		for(char c : arr) 
			count[c - '0']++;
		
		for(int i = 0; i < arr.length; i++) {
			int digit = arr[i] - '0';
			if(digit != count[i]) return false;
		}
		
		return true;
	}