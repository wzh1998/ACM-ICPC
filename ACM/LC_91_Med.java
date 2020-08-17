/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-17 20:08:02
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-17 20:15:37
*/

// Solution with less space consumption
class Solution {
    public int numDecodings(String s) {
        
        // Invalid detection
        if(s.length() == 1) {
            if(s.equals("0")) return 0;
            else return 1;
        }
        else if(s.charAt(0) == '0') return 0;
        
        int dp_i_minus_2 = 1;
        int dp_i_minus_1 = 1;
        int dp_i = 0;
        
        for(int i = 1; i < s.length(); i++) {
            dp_i = dp_i_minus_1;
            
            // Invalid case
            if(s.charAt(0) == 0 || (s.charAt(i) == '0' && (s.charAt(i - 1) == '0' || s.charAt(i - 1) > '2')))
                return 0;
            
            // Valid case
            else if((s.charAt(i - 1) == '1' && s.charAt(i) != '0') || (s.charAt(i - 1) == '2' && s.charAt(i) <= '6' && s.charAt(i) != '0')) {
                dp_i += dp_i_minus_2;
            }
            
            else if(s.charAt(i) == '0'){
                dp_i = dp_i_minus_2;
            }
            
            dp_i_minus_2 = dp_i_minus_1;
            dp_i_minus_1 = dp_i;
            
        }
        return dp_i;
    }
}

// General Solution
class Solution {
    public int numDecodings(String s) {
        
        if(s.length() == 1) {
            if(s.equals("0")) return 0;
            else return 1;
        }
        else if(s.charAt(0) == '0') return 0;
        
        int dp[] = new int[s.length()];
        
        dp[0] = 1;
        
        for(int i = 1; i < s.length(); i++) {
            dp[i] = dp[i - 1];
            
            // Invalid case
            if(s.charAt(0) == 0 || (s.charAt(i) == '0' && (s.charAt(i - 1) == '0' || s.charAt(i - 1) > '2')))
                return 0;
            
            // Valid case
            else if((s.charAt(i - 1) == '1' && s.charAt(i) != '0') || (s.charAt(i - 1) == '2' && s.charAt(i) <= '6' && s.charAt(i) != '0')) {
                dp[i] += (i >= 2) ? dp[i - 2] : 1;
            }
            
            // Special case
            else if(s.charAt(i) == '0'){
                dp[i] = (i >= 2) ? dp[i - 2] : 1;
            }
        }
        return dp[s.length() - 1];
    }
}