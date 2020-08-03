/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-03 19:37:15
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-03 19:37:45
*/

class Solution {
    public void setZeroes(int[][] matrix) {
        int rows = matrix.length;
        int columns = matrix[0].length;
        
        boolean col0 = false;
        
        for(int i = 0; i < rows; i++) {
        	if(matrix[i][0] == 0) col0 = true;
        	for(int j = 1; j < columns; j++) {
        		if(matrix[i][j] == 0) {
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }
        for(int i = rows - 1; i >= 0; i--) {
        	for(int j = columns - 1; j >= 1; j--) {
        		if(matrix[i][0] == 0 || matrix[0][j] == 0) {
        			matrix[i][j] = 0;        		}
        	}
        	if(col0) matrix[i][0] = 0;
        }
    }
}