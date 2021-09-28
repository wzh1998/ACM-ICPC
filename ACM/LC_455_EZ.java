class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int result = 0;
        
        for(int gIdx = g.length - 1, sIdx = s.length - 1; sIdx >= 0 && gIdx >= 0; gIdx--) {
            if(s[sIdx] >= g[gIdx]) {
                result++;
                sIdx--;
            }
        }
        
        return result;
    }
}