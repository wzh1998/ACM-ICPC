/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2021-09-10 21:22:05
* @Last Modified by:   zihaowang
* @Last Modified time: 2021-09-10 21:22:09
*/

class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] result = new int[n];
        
        for(int i = 0; i < bookings.length; i++) {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seat = bookings[i][2];
            
            result[first - 1] += seat;
            if(last < n) result[last] -= seat;
        }
        int accumulate = 0;
        for(int i = 0; i < result.length; i++) {
            result[i] += accumulate;
            accumulate = result[i];
        }
        
        return result;
     }
}