/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-04 10:21:26
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-06 19:12:07
*/
// previous solution: transpose + flip
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

// 2021 my new solution: in place rotation
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        for(int left = 0, right = n - 1; left < right; left++, right--) {
            int i = left;
            for(int j = left; j < right; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
            
        }
    }
    
    
}