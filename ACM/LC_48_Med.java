/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-04 10:21:26
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-04 10:24:25
*/

class Solution {
    public void rotate(int[][] matrix) {
		if(matrix.length == 0) 
			return;
		
        for(int i = 0; i < matrix.length; i++) {
        	for(int j = i + 1; j < matrix[0].length; j++) {
        		matrix[i][j] = matrix[i][j] ^ matrix[j][i];
        		matrix[j][i] = matrix[i][j] ^ matrix[j][i];
        		matrix[i][j] = matrix[i][j] ^ matrix[j][i];
        	}
        	for(int left = 0, right = matrix[0].length-1; left < right; left++, right--) {
        		matrix[i][left] = matrix[i][left] ^ matrix[i][right];
        		matrix[i][right] = matrix[i][left] ^ matrix[i][right];
        		matrix[i][left] = matrix[i][left] ^ matrix[i][right];
        	}
        	
        }
	}
}