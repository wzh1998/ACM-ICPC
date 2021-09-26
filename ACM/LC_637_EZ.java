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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<> ();
        Deque<TreeNode> queue = new LinkedList<> ();
        
        queue.add(root);
        
        while(!queue.isEmpty()) {
            double average = 0;
            int nodeNum = queue.size();
            for(int i = 0;i < nodeNum; i++) {
                TreeNode current = queue.poll();
                average += current.val;
                if(current.left != null) queue.add(current.left);
                if(current.right != null) queue.add(current.right);
            }
            
            result.add(average / nodeNum);
        }
        
        return result;
    }
}