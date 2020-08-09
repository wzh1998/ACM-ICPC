/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-09 11:26:47
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-09 11:26:53
*/

class Solution {
    public long cnk(int N, int K) {
		if(N == K || N == 1) return 1;
		else if(K > N / 2) K = N - K;
		
		long result = 1;
		
		for(int i = 0; i < K; i++) {
			result *= N - i;
			result /= 1 + i;
		}
		
		return result;
	}
	public int uniquePaths(int m, int n) {
        return (int)cnk(m+n-2, n-1);
    }
}