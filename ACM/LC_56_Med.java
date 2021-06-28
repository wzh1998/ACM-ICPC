/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-15 20:12:43
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-06-28 21:04:22
*/

class Solution {
    	public int[][] merge(int[][] intervals) {
        
        List<int[]> results = new ArrayList<> ();
        
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
       
        
        int[] currentInterval = intervals[0];
        results.add(currentInterval);
        
        for(int i = 1; i < intervals.length; i++) {
        	if(intervals[i][0] <= currentInterval[1]) 
        		currentInterval[1] = Math.max(currentInterval[1], intervals[i][1]);
        	else {
        		currentInterval = intervals[i];
        		results.add(currentInterval);
            }
        }
        return results.toArray(new int[results.size()][]);
    }
	
}