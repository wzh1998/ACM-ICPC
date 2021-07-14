/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-07-14 20:23:31
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-07-14 21:13:03
*/

// Solution 1: Depth First Search (DFS)
class Solution {
    public void dfs(int posX, int posY, char[][] grid) {
		if(posX < 0 || posX >= grid[0].length || posY < 0 || posY >= grid.length || grid[posY][posX] == '0') 
			return;
		
		grid[posY][posX] = '0';
		
		dfs(posX - 1, posY, grid);
		dfs(posX + 1, posY, grid);
		dfs(posX, posY - 1, grid);
		dfs(posX, posY + 1, grid);
	}
	
	public int numIslands(char[][] grid) {
		int count = 0;
		
        for(int i = 0; i < grid.length; i++) {
        	for(int j = 0; j < grid[0].length; j++) {
        		if(grid[i][j] == '1') {
        			count++;
        			dfs(j, i, grid);
        		}
        	}
        }
        
        return count;
    }
}

// Solution 1.1: DFS non-recursive version
class Solution {
    public void dfsNonRec(int posX, int posY, char[][] grid) {
		
		Stack<int[]> stack = new Stack<> ();
		stack.push(new int[] {posX, posY});
		
		int[] temp = new int[2];
		
		while(!stack.empty()) {
			temp = stack.pop();
			
			posX = temp[0];
			posY = temp[1];
			grid[posY][posX] = '0';
			
			if(posX - 1 >= 0 && grid[posY][posX - 1]=='1')
				stack.push(new int[] {posX - 1, posY});
			
			if(posX + 1 < grid[0].length && grid[posY][posX + 1]=='1')
				stack.push(new int[] {posX + 1, posY});
			
			if(posY - 1 >= 0 && grid[posY - 1][posX]=='1')
				stack.push(new int[] {posX, posY - 1});
			
			if(posY + 1 < grid.length && grid[posY + 1][posX]=='1')
				stack.push(new int[] {posX, posY + 1});
		}
		
	}
	
	public int numIslands(char[][] grid) {
		int count = 0;
		
        for(int i = 0;i < grid.length; i++) {
        	for(int j = 0; j < grid[0].length; j++) {
        		if(grid[i][j] == '1') {
        			count++;
        			dfsNonRec(j, i, grid);
        		}
        	}
        }
        
        return count;
    }
	
}

// Solution 2: Breadth First Search (BFS)
