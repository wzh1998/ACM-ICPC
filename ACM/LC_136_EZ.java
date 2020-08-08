/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-08 11:16:00
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-08 11:16:15
*/

class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++) {
        	int counter = map.containsKey(nums[i]) ? 2 : 1;
        	map.put(nums[i], counter);
        }
        for(int i = 0; i < nums.length; i++) {
        	if(map.get(nums[i]) == 1)
        		return nums[i];
        }
        return 0;
    }
}