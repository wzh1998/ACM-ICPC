/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-01-02 01:28:24
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-01-02 01:28:27
*/
import java.util.*;


public class Solution {
    /**
     * max water
     * @param arr int整型一维数组 the array
     * @return long长整型
     */
    public long maxWater (int[] arr) {
        int[] maxLeft = new int[1000001];
        int[] maxRight = new int[1000001];
        long result = 0;
               
        maxLeft[0] = arr[0];
        maxRight[arr.length - 1] = arr[arr.length - 1];
        
        for(int i = 1; i < arr.length; i++) 
        	maxLeft[i] = Math.max(maxLeft[i-1], arr[i]);
        
        for(int i = arr.length - 2; i >= 0; i--) 
        	maxRight[i] = Math.max(maxRight[i+1], arr[i]);
        
        for(int i = 0;i < arr.length; i++) 
        	result += Math.min(maxLeft[i], maxRight[i]) - arr[i];
        
        return result;
    }
}