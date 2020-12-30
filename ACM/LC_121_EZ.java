/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-12-30 00:40:09
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-12-30 00:47:32
*/
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int minPrice = Integer.MAX_VALUE;
        
        for(int i = 0; i < prices.length; i++) {
        	if(prices[i] < minPrice) 
        		minPrice = prices[i];
        	else if(prices[i] - minPrice > maxProfit)
        		maxProfit = prices[i] - minPrice;
        }
        
        return maxProfit;
    }
}