// optimised solution
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length < 2) return nums.length;
        
        int wiggle = (nums[0] == nums[1] ? 1 : 2);
        int currDiff = 0;
        int prevDiff = nums[1] - nums[0];
        
        for(int i = 2; i < nums.length; i++) {
            currDiff = nums[i] - nums[i - 1];
            if((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0)) {
                wiggle++;
                prevDiff = currDiff;
            }
        }
        
        return wiggle;
    }
}


// naive solution
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length < 2) return nums.length;
        
        int maxVal = Math.max(nums[0], nums[1]);
        int minVal = Math.min(nums[0], nums[1]);
        
        int diff = nums[1] - nums[0];
        int wiggle = diff == 0 ? 1 : 2;
        
        for(int i = 2; i < nums.length; i++) {
            if(diff < 0) {
                if(nums[i] <= minVal) {
                    minVal = nums[i];
                }
                else {
                    wiggle++;
                    maxVal = nums[i];
                    diff = nums[i] - nums[i - 1];
                }                
            }
                
            else if(diff > 0) {
                if(nums[i] >= maxVal) {
                    maxVal = nums[i];
                }
                else {
                    wiggle++;
                    minVal = nums[i];
                    diff = nums[i] - nums[i - 1];
                }
            }
            else if(nums[i] - nums[i - 1] != diff) {
                wiggle++;
                maxVal = Math.max(maxVal, nums[i]);
                minVal = Math.min(minVal, nums[i]);
                diff = nums[i] - nums[i - 1];
            }
        }
        
        return wiggle;
    }
}