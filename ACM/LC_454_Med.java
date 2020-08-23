/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-23 19:42:59
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-23 19:43:02
*/

class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> hashmap = new HashMap<Integer, Integer> ();
        int result = 0;
        
        for(int i = 0; i < A.length; i++) {
        	for(int j = 0; j < B.length; j++) {
        		int key = A[i] + B[j];
        		hashmap.put(key, hashmap.getOrDefault(key, 0) + 1);
        	}
        }
        
        for(int i = 0; i < C.length; i++) {
        	for(int j = 0; j < D.length; j++) {
        		result += hashmap.getOrDefault(-1 * (C[i] + D[j]), 0);
        	}
        }
        
        return result;
    }
}