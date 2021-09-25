class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<> ();
        
        for(String s : tokens) {
            if(s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                int op2 = stack.pop();
                int op1 = stack.pop();
                int result;
                
                if(s.equals("+"))
                    result = op1 + op2;
                else if(s.equals("-"))
                    result = op1 - op2;
                else if(s.equals("*"))
                    result = op1 * op2;
                else
                    result = op1 / op2;
                
                stack.push(result);
            }
            else
                stack.push(Integer.valueOf(s));
         }
        
        return stack.pop();
    }
}