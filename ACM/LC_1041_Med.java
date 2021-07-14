class Solution {
    public boolean isRobotBounded(String instructions) {
        int direction = 0;
        int xPos = 0;
        int yPos = 0;
        int[][] command = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(int i = 0; i < instructions.length(); i++) {
        	if(instructions.charAt(i) == 'L')
        		direction = (direction + 3) % 4;
        	else if(instructions.charAt(i) == 'R')
        		direction = (direction + 1) % 4;
        	else {
        		xPos += command[direction][0];
        		yPos += command[direction][1];
        	}
        }
        
        
        return (xPos == 0 && yPos == 0) || direction != 0;
    }
}