class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> stack = new Stack<> ();
        int[] result = new int[temperatures.length];
        
        for(int i = 1; i < temperatures.length; i++) {
            if(temperatures[i] <= temperatures[i - 1]) 
                stack.push(i - 1);
            else {
                result[i - 1] = 1;
                
                while((!stack.isEmpty()) && temperatures[i] > temperatures[stack.peek()]) {
                    int prevIdx = stack.pop();
                    result[prevIdx] = i - prevIdx;
                }
            }
        }
        
        return result;
    }
}