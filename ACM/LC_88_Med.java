class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] result = new int[m + n];
        int left, right;
        left = right = 0;
        
        for(int i = 0; i < m + n; i++) {
            if(left == m) {
                for(; right < n; right++, i++) result[i] = nums2[right]; 
            }
            else if(right == n) {
                for(; left < m; left++, i++) result[i] = nums1[left];
            }
            else if(nums1[left] <= nums2[right]) {
                result[i] = nums1[left];
                left++;
            }
            else {
                result[i] = nums2[right];
                right++;
            }
        }
        
        for(int i = 0; i < m + n; i++)
            nums1[i] = result[i];
    }
}