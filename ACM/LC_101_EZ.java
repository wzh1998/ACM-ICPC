class Solution {
    public boolean checkRecur(TreeNode node1, TreeNode node2) {
        if(node1 == null && node2 == null) return true;
        else if(!(node1 != null && node2 != null)) return false;
        
        if(node1.val != node2.val) return false;
        
        return checkRecur(node1.left, node2.right) && checkRecur(node1.right, node2.left);
        
    }
    public boolean isSymmetric(TreeNode root) {
        return checkRecur(root, root);
    }
}