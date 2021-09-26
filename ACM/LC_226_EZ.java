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
    public TreeNode invertTree(TreeNode root) {
        Deque<TreeNode> queue = new LinkedList<> ();
        if(root == null) return root;
        
        queue.add(root);
        
        while(!queue.isEmpty()) {
            TreeNode current = queue.poll();
            
            TreeNode leftChild = current.left;
            TreeNode rightChild = current.right;
            
            if(leftChild != null) queue.add(leftChild);
            if(rightChild != null) queue.add(rightChild);
            
            current.left = rightChild;
            current.right = leftChild;
        }
        
        return root;
    }
}