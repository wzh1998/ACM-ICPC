/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-15 18:42:41
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-15 18:42:45
*/

class Solution {
    long currentNum = Long.MIN_VALUE;
	
	public boolean isValidBST(TreeNode root) {
		if(root == null) return true;
		
		if(root.left == null && root.right == null) {
			boolean result = root.val > currentNum;
			currentNum = root.val;
			return result;
		}
		
		
		if(root.left != null) {
			boolean result = isValidBST(root.left);
			if(!result) return false;
		}
		
		if(root.val <= currentNum) return false;
		currentNum = root.val;
		
		if(root.right != null) {
			boolean result = isValidBST(root.right);
			if(!result) return false;
		}
		
        return true;
    }
}