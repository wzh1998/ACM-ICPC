/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-03 10:08:11
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-03 10:42:06
*/

class Solution {
    public List<Integer> majorityElement(int[] nums) {
		
		List<Integer> result = new ArrayList<> ();
		if(nums.length == 0) return result;
		
        int majorElement1 = nums[0];
        int majorElement2 = nums[0];
        int count1 = 0;
        int count2 = 0;
        
        // Stage 1 - find the two major element
        for(int i = 0; i < nums.length; i++) {
        	
        	
        	if(nums[i] == majorElement1) count1++;
        	else if(nums[i] == majorElement2) count2++; 
        	else if(count1 == 0) {
        		majorElement1 = nums[i];
        		count1 = 1;
        	}
        	else if(count2 == 0) {
        		majorElement2 = nums[i];
        		count2 = 1;
        	}
        	else {
        		count1--;
        		count2--;
        	}
        }
        
        count1 = count2 = 0;
        // Stage 2 - Verification
        for(int i = 0; i < nums.length; i++) {
        	if(nums[i] == majorElement1) count1++;
        	else if(nums[i] == majorElement2) count2++;
        }
        if(count1 > nums.length / 3) result.add(majorElement1);
        if(count2 > nums.length / 3) result.add(majorElement2);
        
        return result;
    }
}