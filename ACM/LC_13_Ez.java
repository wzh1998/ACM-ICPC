class Solution {
    public int romanToInt(String s) {
        int result = 0;
        char[] symbol = new char[]{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int[] value = new int[]{1, 5, 10, 50, 100, 500, 1000};
        
        for(int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            
            for(int j = 0; j < symbol.length; j++) {
                if(symbol[j] == currentChar) {
                    result += value[j];
                    break;
                }
            }
            // check special cases
            if(i >= 1) {
                char prevChar = s.charAt(i - 1);
                if(prevChar == 'I' && (currentChar == 'V' || currentChar == 'X')) 
                    result -= 2;
                else if(prevChar == 'X' && (currentChar == 'L' || currentChar == 'C')) 
                    result -= 20;
                else if(prevChar == 'C' && (currentChar == 'D' || currentChar == 'M')) 
                    result -= 200;
                
            }
        }
        
        return result;
    }
}