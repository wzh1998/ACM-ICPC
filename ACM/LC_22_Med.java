class Solution {
    List<String> result = new ArrayList<>();

    public List<String> generateParenthesis(int n) {

        searchAndAppend(n, 0, "");

        return result;
    }
    public void searchAndAppend(int n, int unbalancedNum, String combination) {

        if(n == 0 && unbalancedNum == 0) 
            result.add(combination);

        if(n > 0) 
            searchAndAppend(n - 1, unbalancedNum + 1, combination + "(");

        if(unbalancedNum > 0) 
            searchAndAppend(n, unbalancedNum - 1, combination + ")");
    }
}

class Solution {
    List<String> result = new ArrayList<> ();
    
    public List<String> generateParenthesis(int n) {
        dfs("", n, 0);
        
        return result;
    }
    
    public void dfs(String s, int n, int unbalance) {
        
        if(n == 0 && unbalance == 0) 
            result.add(s);
        if(n > 0) 
            dfs(s + "(", n - 1, unbalance + 1);
        if(unbalance > 0) 
            dfs(s + ")", n, unbalance - 1);
    }
}