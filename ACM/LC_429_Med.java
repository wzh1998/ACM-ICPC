/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        Deque<Node> queue = new LinkedList<> ();
        
        List<List<Integer>> result = new ArrayList<> ();
        if(root == null) return result;
        
        queue.add(root);
        
        while(!queue.isEmpty()) {
            int nodeNum = queue.size();
            List<Integer> levelResult = new ArrayList<> ();
            
            for(int i = 0; i < nodeNum; i++) {
                Node current = queue.poll();
                List<Node> children = current.children;
                levelResult.add(current.val);
                
                for(int j = 0; j < children.size(); j++) {
                    Node child = children.get(j);
                    if(child != null) queue.add(child);
                }
            }
            
            result.add(levelResult);
        }
        
        return result;
    }
}