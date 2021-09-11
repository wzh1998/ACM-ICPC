/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-09-11 11:09:04
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-11 11:14:09
*/
class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> Integer.compare(b[1], a[1]));
        int result = 0;
        
        for(int[] box : boxTypes) {
            if(truckSize > box[0]) {
                result += box[1] * box[0];
                truckSize -= box[0];
            }
            else {
                result += box[1] * truckSize;
                break;
            }
        }
        
        return result;
    }
}


class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> Integer.compare(b[1], a[1]));
        int result = 0;
        
        for(int i = 0; i < boxTypes.length && truckSize > 0; i++) {
            if(boxTypes[i][0] <= truckSize) {
                result += boxTypes[i][1] * boxTypes[i][0];
                truckSize -= boxTypes[i][0];
            }
            else {
                result += boxTypes[i][1] * truckSize;
                break;
            }
        }
        
        return result;
    }
}