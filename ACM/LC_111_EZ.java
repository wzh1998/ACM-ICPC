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
    public int minDepth(TreeNode root) {
        Deque<TreeNode> queue = new LinkedList<> ();
        int level = 0;
        
        if(root == null) return 0;
        
        queue.add(root);
        
        while(!queue.isEmpty()) {
            int nodeNum = queue.size();
            level++;
            
            for(int i = 0; i < nodeNum; i++) {
                TreeNode current = queue.poll();
                
                if(current.left != null) queue.add(current.left);
                if(current.right != null) queue.add(current.right);
                if(current.left == null && current.right == null) return level;
            }
        }
        
        return level;
    }
}