class Solution {
    public int subarraySum(int[] nums, int k) {
        int sum = 0;
        int result = 0;
        HashMap<Integer, Integer> map = new HashMap<> ();
        
        for(int i = 0; i < nums.length; i++) {
        	map.put(sum, map.getOrDefault(sum, 0) + 1);
            sum += nums[i];
            result += map.getOrDefault(sum - k, 0);
        }
        
        return result;
        
    }
}