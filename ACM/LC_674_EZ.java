class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int result = 1;
        int currentLen = 1;
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] > nums[i - 1]) currentLen++;
            else currentLen = 1;
            
            result = Math.max(result, currentLen);
        }
        
        return result;
    }
}