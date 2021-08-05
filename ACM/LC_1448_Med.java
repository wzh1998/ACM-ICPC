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
    int goodNodes = 0;
    
    public int goodNodes(TreeNode root) {
        if(root == null) return 0;
        
        dfs(root, root.val);
        return goodNodes;
    }
    
    public void dfs(TreeNode root, int branchMax) {
        if(root == null) return;
        else if(root.val >= branchMax) {
            goodNodes++;
            branchMax = root.val;
        }
        dfs(root.left, branchMax);
        dfs(root.right, branchMax);
    }
	
}

// alternative method without using global variable
class Solution {
    
    public int goodNodes(TreeNode root) {
        if(root == null) return 0;
        
        return dfs(root, root.val);
    }
    
    public int dfs(TreeNode root, int branchMax) {
        int goodNodes = 0;
        
        if(root == null) return 0;
        else if(root.val >= branchMax) {
            goodNodes++;
            branchMax = root.val;
        }
        goodNodes += dfs(root.left, branchMax);
        goodNodes += dfs(root.right, branchMax);
        
        return goodNodes;
    }
    
}