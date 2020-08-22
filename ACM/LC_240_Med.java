/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-22 10:37:16
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-22 10:42:12
*/

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
		if(matrix.length == 0) return false;
        int row = 0;
        int column = matrix[0].length - 1;
        while(row < matrix.length && column >= 0) {
        	if(target > matrix[row][column]) row++;
        	else if(target < matrix[row][column]) column--;
        	else return true;
        }
        
        return false;
    }
}