public String addStrings(String num1, String num2) {
		
        int num1Idx = num1.length() - 1;
        int num2Idx = num2.length() - 1;
        
        String result = "";
        
        int op1 = (num1Idx < 0 ? 0 : num1.charAt(num1Idx) - '0');
    	int op2 = (num2Idx < 0 ? 0 : num2.charAt(num2Idx) - '0');
    	int carry = 0;
    	int digit;
    	
        while(num1Idx >= 0 || num2Idx >= 0) {
        	op1 = (num1Idx < 0 ? 0 : num1.charAt(num1Idx) - '0');
        	op2 = (num2Idx < 0 ? 0 : num2.charAt(num2Idx) - '0');
        	
        	int op = op1 + op2 + carry;
        	digit = op % 10;
        	result = Integer.toString(digit) + result;
        	carry = op / 10;
        	
        	num1Idx--;
        	num2Idx--;
        	
        }
        result = (carry == 0 ? result : Integer.toString(carry) + result);
        
        return result;
    }