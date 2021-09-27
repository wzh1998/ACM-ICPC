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
    public int findDepth(TreeNode root, int depth) {
        if(root == null) return depth;
        
        int leftDepth = findDepth(root.left, depth + 1);
        int rightDepth = findDepth(root.right, depth + 1);
        
        if(depth == -1 || Math.abs(leftDepth - rightDepth) > 1) return -1;
        else return Math.max(leftDepth, rightDepth);
    }
    public boolean isBalanced(TreeNode root) {
        
        return findDepth(root, 0) != -1;
        
    }
}