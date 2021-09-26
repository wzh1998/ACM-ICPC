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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Deque<TreeNode> queue = new LinkedList<> ();
        List<List<Integer>> result = new ArrayList<> ();
        if(root == null) return result;
        
        queue.add(root);
        
        while(!queue.isEmpty()) {
            int nodeNum = queue.size();
            List<Integer> currentLevel = new ArrayList<> ();

            for(int i = 0; i < nodeNum; i++) {
                TreeNode current = queue.poll();
                currentLevel.add(current.val);
                if(current.left != null) queue.add(current.left);
                if(current.right != null) queue.add(current.right);
            }
            result.add(currentLevel);
        }
        
        return result;
    }
}