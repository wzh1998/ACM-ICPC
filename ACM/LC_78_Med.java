/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-07-30 14:20:47
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-07-30 14:52:17
*/

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List <List<Integer>> result = new ArrayList<List<Integer>>();
        
        for(int mask = 0; mask < (1<<nums.length); mask++) {
            List <Integer> currentList = new ArrayList<Integer>();
        	int temp = mask;
        	
        	for(int i = 0; temp > 0; i++) {
        		if(temp % 2 == 1) {
        			currentList.add(nums[i]);
        		}
        		temp >>= 1;
        	}
        	result.add(currentList);
        }
        
        return result;
    }
}