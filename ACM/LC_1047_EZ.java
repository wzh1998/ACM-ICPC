class Solution {
    public String removeDuplicates(String s) {
        Deque<Character> queue = new LinkedList<> ();
        for(char c : s.toCharArray()) {
            if(queue.isEmpty() || queue.getLast() != c) 
                queue.addLast(c);
            else
                queue.pollLast();
        }
        
        StringBuilder sb = new StringBuilder();
        while(!queue.isEmpty()) 
            sb.append(queue.pollFirst());
        
        return sb.toString();
    }
}