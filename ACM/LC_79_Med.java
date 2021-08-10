/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-08 20:20:56
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-10 17:53:33
*/

// 2021 solution
class Solution {
    boolean[][] visited;
    boolean result;
    
    public boolean exist(char[][] board, String word) {
        visited = new boolean[board.length][board[0].length];
        result = false;
        
        for(int y = 0; y < board.length; y++) {
            for(int x = 0; x < board[0].length; x++) {
                dfs(board, word, 0, y, x);
                if(result) return true;
            }
        }
        
        return result;
    }
    
    public void dfs(char[][] board, String word, int count, int y, int x) {
        if(count == word.length()) {
            result = true;
            return;
        }
            
        if(y >= board.length || y < 0 || x >= board[0].length || x < 0)
            return;
        if(visited[y][x])
            return;
        
        if(board[y][x] == word.charAt(count)) {
            visited[y][x] = true;
            dfs(board, word, count + 1, y, x + 1);
            dfs(board, word, count + 1, y, x - 1);
            dfs(board, word, count + 1, y + 1, x);
            dfs(board, word, count + 1, y - 1, x);
            visited[y][x] = false;
            
            if(result) return;
        }
    }
}

// 2020 solution
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
}