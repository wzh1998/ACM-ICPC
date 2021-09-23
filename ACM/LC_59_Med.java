class Solution {
    public int[][] generateMatrix(int n) {
        int count = 0;
        int[][] result = new int[n][n];
        
        for(int iter = 0; count < n * n; iter++) {
            int x = iter;
            int y = iter;
            
            if(n % 2 == 1 && iter == n / 2) {
                result[y][x] = ++count;
                break;
            }
            // right
            for(; x < n - 1 - iter; x++) 
                result[y][x] = ++count;
            // down
            for(; y < n - 1 - iter; y++)
                result[y][x] = ++count;
            // left
            for(; x > iter; x--) 
                result[y][x] = ++count;
            // up
            for(; y > iter; y--)
                result[y][x] = ++count;                 
        }
        return result;
    }
}