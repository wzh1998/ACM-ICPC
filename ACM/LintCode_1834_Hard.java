public class Solution {
    /**
     * @param n: the number of people
     * @param m: the number of groups
     * @return: the number of grouping options
     */
    public long groupingOptions(int n, int m) {
        // write your code here
        if(n < m) return 0;
        else if(n == m) return 1;

        int spaceNum = n - m;
        int objectNum = m;

        long[][] dp = new long[objectNum + 1][spaceNum + 1];

        for(int i = 1; i <= objectNum && i <= spaceNum; i++) {
            dp[i][i] = 1;
        }
        
        for(int i = 1; i <= objectNum; i++) {
            for(int j = 1; j <= spaceNum; j++) {
                if(j < i) 
                    dp[i][j] = dp[i - 1][j];
                else 
                    dp[i][j] += dp[i - 1][j] + dp[i][j - i];
            }
        }

        return dp[objectNum][spaceNum];
    }
}