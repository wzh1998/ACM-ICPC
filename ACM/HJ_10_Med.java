/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-18 13:31:15
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-18 13:31:17
*/
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int result = 0;
        String s = sc.nextLine();
        boolean[] mark = new boolean[128];
        for(int i = 0; i < mark.length; i++) {
            mark[i] = false;
        }
        for(int i = 0; i < s.length(); i++) {
            if(!mark[s.charAt(i)]) {
                mark[s.charAt(i)] = true;
                result++;
            }
        }
        
        System.out.print(result);
    }
}