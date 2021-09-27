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
// recursive solution
class Solution {
    public int findDepth(TreeNode node, int depth) {
        if(node == null) return depth;
        return Math.max(findDepth(node.left, depth + 1), findDepth(node.right, depth + 1));
    }
    public int maxDepth(TreeNode root) {
        
        return findDepth(root, 0);
    }
}

// iterative solution
class Solution {
    public int maxDepth(TreeNode root) {
        Deque<TreeNode> queue = new LinkedList<> ();
        if(root == null) return 0;
        queue.add(root);
        int level = 0;
        
        while(!queue.isEmpty()) {
            int nodeNum = queue.size();
            level++;
            for(int i = 0; i < nodeNum; i++) {
                TreeNode current = queue.poll();
                if(current.left != null) queue.add(current.left);
                if(current.right != null) queue.add(current.right);
                
            }
        }
        
        return level;
    }
}