/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-08-06 19:13:47
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-06 19:13:55
*/

class Solution {
    List<String> results = new ArrayList<> ();
    String digits;
    
    public List<String> letterCombinations(String digits) {
        this.digits = digits;
        if(digits.length() == 0) return results;
        
        dfs(new StringBuilder(), 0);
        
        return results;
    }
    
    public void dfs(StringBuilder s, int idx) {
        if(idx == digits.length()) {
            results.add(s.toString());
            return;
        }
        
        if(digits.charAt(idx) == '2') {
            dfs(new StringBuilder(s.toString()).append("a"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("b"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("c"), idx + 1);
        }
        else if(digits.charAt(idx) == '3') {
        	dfs(new StringBuilder(s.toString()).append("d"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("e"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("f"), idx + 1);
        }
        else if(digits.charAt(idx) == '4') {
        	dfs(new StringBuilder(s.toString()).append("g"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("h"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("i"), idx + 1);
        }
        else if(digits.charAt(idx) == '5') {
        	dfs(new StringBuilder(s.toString()).append("j"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("k"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("l"), idx + 1);
        }
        else if(digits.charAt(idx) == '6') {
        	dfs(new StringBuilder(s.toString()).append("m"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("n"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("o"), idx + 1);
        }
        else if(digits.charAt(idx) == '7') {
        	dfs(new StringBuilder(s.toString()).append("p"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("q"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("r"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("s"), idx + 1);
        }
        else if(digits.charAt(idx) == '8') {
        	dfs(new StringBuilder(s.toString()).append("t"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("u"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("v"), idx + 1);
        }
        else if(digits.charAt(idx) == '9') {
        	dfs(new StringBuilder(s.toString()).append("w"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("x"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("y"), idx + 1);
            dfs(new StringBuilder(s.toString()).append("z"), idx + 1);
        }
    }
}