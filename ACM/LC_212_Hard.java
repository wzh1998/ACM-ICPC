/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-08 20:43:55
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-08 20:44:01
*/

class Solution {
    boolean[][] access;
	public boolean dfs(char[][] board, String word, int index, int row, int column) {
		if(board[row][column] != word.charAt(index)) return false;
		if(index == word.length() - 1) return true;
		
		
		boolean result = false;
		access[row][column] = true;
		// up
		if(row > 0 && !access[row - 1][column] && !result) 
			result =  dfs(board, word, index + 1, row - 1, column);
		// down
		if(row < board.length-1 && !access[row + 1][column] && !result) 
			result =  dfs(board, word, index + 1, row + 1, column);
		// left
		if(column > 0 && !access[row][column - 1] && !result) 
			result =  dfs(board, word, index + 1, row, column - 1);
		// right
		if(column < board[0].length-1 && !access[row][column + 1] && !result) 
			result =  dfs(board, word, index + 1, row, column + 1);
		
		access[row][column] = false;
		
		return result;
	}
	public boolean exist(char[][] board, String word) {
		boolean result = false;
		access = new boolean[board.length][board[0].length];
		for(int i = 0; i < access.length; i++) {
			for(int j = 0; j < access[0].length; j++) {
				access[i][j] = false;
			}
		}
		for(int i = 0; i < access.length; i++) {
			for(int j = 0; j < access[0].length; j++) {
				result = dfs(board, word, 0, i, j);
				if(result) return true;
			}
		}
		return false;
    }
	public List<String> findWords(char[][] board, String[] words) {
        
		List<String> result = new ArrayList<> ();
		for(int i = 0; i < words.length; i++) {
			if(exist(board, words[i]))
				result.add(words[i]);
		}
		return result;
    }
}