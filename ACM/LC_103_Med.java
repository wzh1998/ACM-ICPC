/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-22 20:13:55
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-22 20:14:00
*/
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		
        Stack<TreeNode> stack1 = new Stack<> ();
        Stack<TreeNode> stack2 = new Stack<> ();
        List<List<Integer>> result = new ArrayList<> ();

        if(root == null) return result;
        
        Stack<TreeNode> temp;
        TreeNode current;
        boolean zig = true;
        
        stack1.push(root);
        
        while(!stack1.isEmpty()) {
        	List<Integer> list= new ArrayList<> ();
        	while(!stack1.isEmpty()) {
        		current = stack1.pop();
        		list.add(current.val);
        		if(zig) {
        			if(current.left != null) stack2.add(current.left);
            		if(current.right != null) stack2.add(current.right);
        		}
        		else {
        			if(current.right != null) stack2.add(current.right);
            		if(current.left != null) stack2.add(current.left);
        		}
        	}
    		zig = !zig;
        	result.add(list);
        	temp = stack1;
        	stack1 = stack2;
        	stack2 = temp;
        }
        
        return result;
    }
}
