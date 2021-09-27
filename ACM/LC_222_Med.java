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
    
    public int countNodes(TreeNode root) {
        if(root == null) return 0;
        
        int leftDepth = 0;
        int rightDepth = 0;
        
        TreeNode leftTreeNode = root;
        TreeNode rightTreeNode = root; 
        
        while(leftTreeNode != null) {
            leftTreeNode = leftTreeNode.left;
            leftDepth++;
        }
        while(rightTreeNode != null) {
            rightTreeNode = rightTreeNode.right;
            rightDepth++;
        }
        
        if(leftDepth == rightDepth) 
            return (2 << (leftDepth - 1)) - 1;
        
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
}