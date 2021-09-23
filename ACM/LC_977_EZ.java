class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] result = new int[nums.length];
        int idx = nums.length - 1;
        
        int left = 0;
        int right = nums.length - 1;
        
        while(left <= right) {
            if(Math.abs(nums[left]) > Math.abs(nums[right])) {
                result[idx--] = nums[left] * nums[left];
                left++;
            }
            else {
                result[idx--] = nums[right] * nums[right];
                right--;
            }
        }
        
        return result;
    }
}


class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] result = new int[nums.length];
        int idx = 0;
        
        int right = 0;
        while(right < nums.length && nums[right] < 0)
            right++;
        
        int left = right - 1;
        
        while(left >= 0 && right < nums.length) {
            if(Math.abs(nums[left]) <= Math.abs(nums[right])) {
                result[idx] = nums[left] * nums[left];
                left--;
            }
            else {
                result[idx] = nums[right] * nums[right];
                right++;

            }
            idx++;
        }
        
        while(left >= 0) {
            result[idx] = nums[left] * nums[left];
            idx++;
            left--;
        }
        while(right < nums.length) {
            result[idx] = nums[right] * nums[right];
            idx++;
            right++;
        }
        
        return result;
    }
}