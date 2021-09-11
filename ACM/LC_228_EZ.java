/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-09-11 10:44:53
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-11 10:45:14
*/
class Solution {
    public List<String> summaryRanges(int[] nums) {
        
        List<String> result = new ArrayList<> ();
        if(nums == null || nums.length == 0) return result;
        
        int lower = nums[0];
        int upper = nums[0];
        
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] == nums[i - 1] + 1) 
                upper++;
            else {
                String range = String.valueOf(lower) + (lower == upper ? "" : "->" + String.valueOf(upper));
                result.add(range);
                lower = nums[i];
                upper = nums[i];
            }
        }
        // add the last range
        String range = String.valueOf(lower) + (lower == upper ? "" : "->" + String.valueOf(upper));
        result.add(range);
        
        return result;
    }
}