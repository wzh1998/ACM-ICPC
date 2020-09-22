/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-22 17:28:46
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-22 17:28:52
*/

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