/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-06-27 15:14:25
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-06-27 15:14:56
*/
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
		
		List<List<Integer>> result = new ArrayList<>();
        if(nums.length < 3) return result;
        
        Arrays.sort(nums);
        for(int i = 0; i < nums.length - 2; i++) {
        	if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
        		int target = -nums[i];
            	int front = i + 1;
            	int back = nums.length - 1;
            	
            	while(front < back) {
            		int currentSum = nums[front] + nums[back];
            		if(currentSum < target) front++;
            		else if(currentSum > target) back--;
            		else {
            			List<Integer> currentComb = new ArrayList<>();
            			int frontVal = nums[front];
            			int backVal = nums[back];
            			
            			currentComb.add(-target);
            			currentComb.add(frontVal);
            			currentComb.add(backVal);
            			result.add(currentComb);
            			
            			while(front < back - 1) {
            				front++;
            				if(nums[front] != frontVal) break;
            			}
            			while(back > front) {
            				back--;
            				if(nums[back] != backVal) break;
            			}
            		}
            	}
        	}
        }
        return result;
    }
}