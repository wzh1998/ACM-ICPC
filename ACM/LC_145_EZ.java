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
    public void traversal(TreeNode currentNode, List<Integer> result) {
        if(currentNode == null) return;
        
        traversal(currentNode.left, result);
        traversal(currentNode.right, result);
        result.add(currentNode.val);
            
    } 
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<> ();
        traversal(root, result);
        
        return result;
    }
}