/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-07-30 20:12:28
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-07-30 20:12:36
*/

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<Integer> ();

		int rows = matrix.length;
		if(rows == 0) return result;
		
        int columns = matrix[0].length;
        int elementNum = columns * rows;
        int round = 0;
        int counter = 0;
        
        while(counter < elementNum) {
        	for(int currentCol = round; currentCol <= columns - 1 - round; currentCol++) {
        		result.add(matrix[round][currentCol]);
        		counter++;
        		if(counter == elementNum) return result;
        	}
        	for(int currentRow = round + 1; currentRow <= rows - 1 - round; currentRow++) {
        		result.add(matrix[currentRow][columns-round-1]);
        		counter++;
        		if(counter == elementNum) return result;
        	}
        	for(int currentCol = columns - 2 - round; currentCol >= 1 + round; currentCol--) {
        		result.add(matrix[rows-1-round][currentCol]);
        		counter++;
        		if(counter == elementNum) return result;
        	}
        	for(int currentRow = rows - 1 - round; currentRow >= 1 + round; currentRow--) {
        		result.add(matrix[currentRow][round]);
        		counter++;
        		if(counter == elementNum) return result;
        	}
        	round++;
        }
        return result;
    }
}