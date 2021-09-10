/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-09-10 12:44:22
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-10 12:48:34
*/
// optimised for faster speed
class Solution {
    public int countBinarySubstrings(String s) {
        
        int prevNum = 0;
        int currentNum = 1;
        int result = 0;
        
        char[] arr = s.toCharArray();
        for(int i = 1; i < s.length(); i++) {
            if(arr[i] == arr[i - 1]) 
                currentNum++;
                
            else {
                result += Math.min(currentNum, prevNum);
                prevNum = currentNum;
                currentNum = 1;
            }
        }
        
        return (result + Math.min(currentNum, prevNum));
    }
}


class Solution {
    public int countBinarySubstrings(String s) {
        
        int prevNum = 0;
        int currentNum = 1;
        int result = 0;
        
        char c = s.charAt(0);
        
        for(int i = 1; i < s.length(); i++) {
            
            if(s.charAt(i) == c) 
                currentNum++;
                
            else {
                c = s.charAt(i);
                prevNum = currentNum;
                currentNum = 1;
            }
            if(currentNum <= prevNum) result++;
        }
        
        return result;
    }
}