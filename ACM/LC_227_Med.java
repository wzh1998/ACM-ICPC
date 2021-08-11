class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<> ();
        
        int num = 0;
        int result = 0;
        
        char currentChar;
        char sign = '+';
        
        
        for(int i = 0; i <= s.length(); i++) {
            currentChar = (i != s.length() ? s.charAt(i) : '+');
            
            if(currentChar == ' ')
                continue;
            else if(Character.isDigit(currentChar)) 
                num = num * 10 + currentChar - '0';
            else {
                if(sign == '+') 
                    stack.push(num);
                
                else if(sign == '-') 
                    stack.push(-num);
                
                else if(sign == '*') 
                    stack.push(stack.pop() * num);
                    
                else if(sign == '/') 
                    stack.push(stack.pop() / num);
                
                num = 0;
                sign = currentChar;
            }
        }
        
        while(!stack.isEmpty()) 
            result += stack.pop();
        
        return result;
        
    }
    
}