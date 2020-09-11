/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-11 21:10:12
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-12 00:06:32
*/
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
		int sum;
        for(int i = 0; i < gas.length; i++) {
        	gas[i] -= cost[i];
        }
        for(int i = 0; i < gas.length; i++) {
        	sum = 0;
        	for(int j = 0; j < gas.length; j++) {
        		sum += gas[(i + j) % gas.length];
        		if(sum < 0) break;
        	}
        	if(sum >= 0) return i;
        }
        return -1;
    }
}