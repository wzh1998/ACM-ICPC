//Optimised solution
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] map = new int[60];
        int result = 0;
        
        for(int i = 0; i < time.length; i++) {
            int key = time[i] % 60;
            map[key]++;
        }
        
        for(int i = 0; i < time.length; i++) {
            int key = 60 - (time[i] % 60);
            if(key == 60) key = 0;
            
            result += map[key];
            
            if(key == (time[i] % 60)) 
                result--;
        }
        
        return result / 2;
    }
}

// Original HashMap solution
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        Map<Integer, Integer> map = new HashMap<> ();
        int result = 0;
        
        for(int i = 0; i < time.length; i++) {
            int key = time[i] % 60;
            map.put(key, map.getOrDefault(key, 0) + 1);
        }
        
        for(int i = 0; i < time.length; i++) {
            int key = 60 - (time[i] % 60);
            if(key == 60) key = 0;
            
            if(key == (time[i] % 60)) 
                result += map.get(key) - 1;
            else
                result += map.getOrDefault(key, 0);
        }
        
        return result / 2;
    }
}