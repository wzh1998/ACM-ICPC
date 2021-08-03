class Solution {
    public void nextPermutation(int[] nums) {
        for(int i = nums.length - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
                // find idx and swap
                int k = idxOfNextGreater(nums, i - 1);
                int temp = nums[i - 1];
                nums[i - 1] = nums[k];
                nums[k] = temp;
                
                // sort RHS
                reverseRHS(nums, i);
                return;
            }
        }
        
        reverseRHS(nums, 0);
    }
    public int idxOfNextGreater(int[] nums, int idx) {
        int target = nums[idx];
        for(int i = nums.length - 1; i > idx; i--) {
            if(nums[i] > target)
                return i;
        }
        return idx;
    }
        
    public void reverseRHS(int[] nums, int idx) {
        int left = idx;
        int right = nums.length - 1;
        while(left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            
            left++;
            right--;
        }
    }
}