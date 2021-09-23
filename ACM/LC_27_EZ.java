class Solution {
    public int removeElement(int[] nums, int val) {
        int currentPos = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != val) 
                nums[currentPos++] = nums[i];
        }
        
        return currentPos;
    }
}