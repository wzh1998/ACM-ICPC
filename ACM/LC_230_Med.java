/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-22 11:54:22
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-22 11:54:26
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack <TreeNode> stack = new Stack<TreeNode> ();
        while(true) {
        	while(root != null) {
            	stack.push(root);
            	root = root.left;
            }
            root = stack.pop();
            k--;
            
            if(k == 0) return root.val;
            root = root.right;
        }
    }
}