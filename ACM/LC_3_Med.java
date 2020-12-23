/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-15 20:27:31
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-12-23 23:22:56
*/


// Advanced Method: Two pointers
class Solution {
    int left = 0;
    int right = 0;
    int result = 0;
    
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<> ();
        
        while(right < s.length()) {
            if(map.containsKey(s.charAt(right))) {
                if(map.get(s.charAt(right)) >= left)
                    left = map.get(s.charAt(right)) + 1;
                
                map.replace(s.charAt(right), right);
            }
            else if(!map.containsKey(s.charAt(right)))
                map.put(s.charAt(right), right);
            
            right++;
            result = Math.max(result, right - left);
        }
        
        return result;
    }
}

// Naive Method
class Solution {
    public int lengthOfLongestSubstring(String s) {
		int result = 0;
        int counter = 0;
        int currentIdx = 0;
        
        Map<Character, Integer> map = new HashMap<> ();
        while(currentIdx < s.length()) {
        	if(map.containsKey(s.charAt(currentIdx))) {
        		result = Math.max(result, counter);
        		currentIdx = map.get(s.charAt(currentIdx)) + 1;
        		counter = 0;
        		map.clear();
        	} 
        	else {
        		map.put(s.charAt(currentIdx), currentIdx);
        		counter++;
        		currentIdx++;
        	}
        }
        result = Math.max(result, counter);
        
        return result;
    }
}