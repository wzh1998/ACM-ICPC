/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-22 17:28:46
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-22 19:35:06
*/

// Iterasive solution
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> list = new ArrayList<> ();
		Stack<TreeNode> stack = new Stack<> ();
		TreeNode current = root;
		
		while(true) {
			while(current != null) {
				stack.push(current);
				current = current.left;
			}
			if(stack.isEmpty()) return list;
			current = stack.pop();
			list.add(current.val);
			current = current.right;
		}
    }
}

// Recursive solution
class Solution {
    List<Integer> result = new ArrayList<> ();
	
	public void traversal(TreeNode root) {
		if(root == null) return;
		traversal(root.left);
		result.add(root.val);
		traversal(root.right);
	}
	
	public List<Integer> inorderTraversal(TreeNode root) {
		traversal(root);
		return result;
    }
}