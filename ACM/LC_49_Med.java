/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-23 20:55:31
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-23 20:55:35
*/

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> hashmap = new HashMap<> ();
        for(int i = 0; i < strs.length; i++) {
        	char[] sequence = new char[26];
        	for(int j = 0; j < strs[i].length(); j++) {
        		sequence[strs[i].charAt(j) - 'a']++;
        	}
        	String key = Arrays.toString(sequence);
        	if(!hashmap.containsKey(key)) hashmap.put(key, new ArrayList<String> ());
        	hashmap.get(key).add(strs[i]);
        }
        return new ArrayList<> (hashmap.values());
    }
}