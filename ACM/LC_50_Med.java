/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-18 18:23:20
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-18 18:23:22
*/

class Solution {
    public double myPow(double x, int n) {
		
		if(n < 0) {
			n = (n == Integer.MIN_VALUE) ? -(n+2) : -n;
			x = 1 / x;
		}
		double result = 1;

        while(n > 0) {
        	if((n & 1) > 0) result *= x;
        	x *= x;
        	n >>= 1;
        }
        
        return result;
    } 
}