/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-08-26 14:56:43
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-08-26 14:56:53
*/

class Solution {
    public String originalDigits(String s) {
        
        int[] numFreq = new int[10];
        int[] charFreq = new int[128];
        
        for(char c : s.toCharArray())  
            charFreq[c]++;
        
        // The freq of each even number == the freq of their unique character
        numFreq[0] = charFreq['z'];
        numFreq[2] = charFreq['w'];
        numFreq[4] = charFreq['u'];
        numFreq[6] = charFreq['x'];
        numFreq[8] = charFreq['g'];
        
        // Computing the freq for odd numbers
        // 'h' appears only in 3 and 8, so the freq of 3 = freq('h') - freq(8)
        numFreq[3] = charFreq['h'] - numFreq[8];
        numFreq[5] = charFreq['f'] - numFreq[4];
        numFreq[7] = charFreq['s'] - numFreq[6];
        
        numFreq[1] = charFreq['o'] - numFreq[0] - numFreq[2] - numFreq[4];
        numFreq[9] = charFreq['i'] - numFreq[5] - numFreq[6] - numFreq[8];
        
        StringBuilder ret = new StringBuilder();
        for(int i = 0; i < 10; i++) 
            for(int j = 0; j < numFreq[i]; j++) ret.append(i);
            
        return ret.toString();
    }
}