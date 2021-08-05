/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-08-05 19:10:33
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-05 19:10:50
*/

// using StringBuilder is much faster than manipulating on String.
class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        
        String first = strs[0];
        String last = strs[strs.length - 1];
        // String result = "";
        StringBuilder result = new StringBuilder();
        
        
        for(int i = 0; i < first.length() && i < last.length(); i++) {
            if(first.charAt(i) != last.charAt(i))
                break;
            result.append(first.charAt(i));
        }
        
        return result.toString();
    }
}