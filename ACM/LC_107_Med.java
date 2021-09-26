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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<> ();
        if(root == null) return result;
        Queue<TreeNode> queue = new LinkedList<> ();
        queue.add(root);
        
        while(!queue.isEmpty()) {
            int nodeNum = queue.size();
            List<Integer> levelResult = new ArrayList<> ();
            for(int i = 0; i < nodeNum; i++) {
                TreeNode current = queue.poll();
                
                levelResult.add(current.val);
                if(current.left != null) queue.add(current.left);
                if(current.right != null) queue.add(current.right);
            }
            result.add(0, levelResult);
        }
                                 
        return result;
    }
}