/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-07-20 20:56:33
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-07-20 21:13:48
*/

class Solution {
    Map <Character, Integer> map = new HashMap<> ();
	
	public boolean isAlienSorted(String[] words, String order) {
        
        for(int i = 0; i < order.length(); i++)
        	map.put(order.charAt(i), i);
        for(int i = 0; i < words.length - 1; i++) {
        	if(!isSmaller(words[i], words[i + 1]))
        		return false;
        }
        return true;
    }
	
	public boolean isSmaller(String a, String b) {
		
		for(int i = 0; i < Math.min(a.length(), b.length()); i++) {
			if(a.charAt(i) != b.charAt(i)) 
				return map.get(a.charAt(i)) <= map.get(b.charAt(i));
		}
		
		return a.length() <= b.length();
	}
}