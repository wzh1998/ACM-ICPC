/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-08-05 20:27:59
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-05 20:39:16
*/

// Optimised attempt
class Solution {
    public String removeDuplicates(String s, int k) {
        StringBuilder stack = new StringBuilder ();
        int[] count = new int[s.length()];
        int idx = 0;
        
        for(char currentChar : s.toCharArray()) {
            count[idx] = (idx == 0 || currentChar != stack.charAt(stack.length() - 1)) ? 1 : (count[idx - 1] + 1);
            idx++;
            stack.append(currentChar);
            
            if(count[idx - 1] == k) {
                stack.delete(idx - k, idx);
                idx -= k;
            }
        }
        
        return stack.toString();
    }
}

// First attempt
class Solution {
    public String removeDuplicates(String s, int k) {
        Stack<Character> stack = new Stack<> ();
        Stack<Integer> balance = new Stack<> ();
        
        
        for(int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            
            if(stack.isEmpty() || currentChar != stack.peek()) {
                stack.push(currentChar);
                balance.push(1);
            }
            else if(currentChar == stack.peek()) {
                if(k == balance.peek() + 1) {
                    for(int j = 0; j < k - 1; j++) {
                        stack.pop();
                        balance.pop();
                    }
                }
                else {
                    stack.push(currentChar);
                    balance.push(balance.peek() + 1);
                }
            }
        }
        
        StringBuilder result = new StringBuilder();
        while(!stack.isEmpty()) 
            result.append(stack.pop());
        
        return result.reverse().toString();
    }
}