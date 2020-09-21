/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-21 23:39:41
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-21 23:39:44
*/
class Solution {
    public boolean isValid(String s) {
        char[] st = new char[100000];
        int len = s.length();
        int index = 1;
        for(int i = 0;i < len;i++) {
            char currentChar = s.charAt(i);
            if(currentChar=='(' || currentChar=='[' || currentChar=='{') {
                st[index] = currentChar;
                index++;
            } else if((st[index-1]=='(' && currentChar==')') || (st[index-1]=='[' && currentChar==']') || (st[index-1]=='{' && currentChar=='}')) {
                index--;
            } else {
                return false;
            }
        }
        return (index==1) ? true : false;
    }
}