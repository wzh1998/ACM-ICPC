/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-08-11 23:28:33
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-11 23:46:57
*/

// optimised solution
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while(i >= 0 && j >= 0) {
            if(A[i] > B[j])
                A[k] = A[i--];
            else 
                A[k] = B[j--];
            k--;
        }
        while(j >= 0) {
            A[k] = B[j--];
            k--;
        }
    }
}


// original solution
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