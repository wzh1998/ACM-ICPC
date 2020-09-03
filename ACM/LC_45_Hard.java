/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-03 17:45:32
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-03 20:17:03
*/

// 总结：能走到后面就一定能走到前面，但反过来却并非如此。
// 因此对于到某一点x，
// 若能从 x-10 跳转到 x，那么没有必要考虑从 x-5 跳转的情况，因为 x-5 -> x 所消耗的最小步数顶多与 x-10 -> x 持平
// 且有可能更糟。因此利用 two pointers 及 greedy 思想可写出更有解
// 重要特性：dp数组为递增数组，利用此性质可以优化算法，不用每次都从0遍历j

// AC solution with O(n) time, two pointers, greedy.
class Solution {
    public int jump(int[] nums) {
        int[] dp = new int[nums.length];
        int prevIdx = 0;
        dp[0] = 0;
        
        for(int i = 1; i < nums.length; i++) {
        	for(; prevIdx < i; prevIdx++) {
        		if(prevIdx + nums[prevIdx] >= nums.length - 1)
        			return dp[prevIdx] + 1;
        		else if(prevIdx + nums[prevIdx] >= i) {
        			dp[i] = dp[prevIdx] + 1;
        			break;
        		}
        	}
        }
        return dp[nums.length - 1];
    }
}


// AC solution with condition break, 282ms, still need to improve.
class Solution {
    public int jump(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = 0;
        
        for(int i = 1; i < nums.length; i++) {
        	for(int j = 0; j < i; j++) {
        		if(j + nums[j] >= nums.length - 1)
        			return dp[j] + 1;
        		else if(j + nums[j] >= i) {
        			dp[i] = dp[j] + 1;
        			break;
        		}
        	}
        }
        return dp[nums.length - 1];
    }
}


//DP - O(N^2) - TLE 
class Solution {
    public int jump(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = 0;

        for(int i = 1; i < dp.length; i++) dp[i] = (1 << 31) - 1;
        
        for(int i = 0; i < nums.length; i++) {
        	for(int j = 0; j < i; j++) {
        		if(j + nums[j] >= i) {
        			dp[i] = Math.min(dp[i], dp[j] + 1);
        		}
        	}
        }
        return dp[nums.length - 1];
    }
}
