/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-08 11:30:27
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-08 12:07:39
*/

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        
        for(int i = 0; i < s.length(); i++) {
        	dp[i+1] = false;
        	for(int j = 0; j <= i; j++) {
        		if(dp[j] && wordDict.contains(s.substring(j, i+1)))
        			dp[i+1] = true;
        	}
        }
        
        return dp[s.length()];
    }
}