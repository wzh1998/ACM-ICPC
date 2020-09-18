/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-18 13:22:38
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-18 13:39:03
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        for(int i = 0; i < s.length(); i++) {
        	System.out.print(s.charAt(s.length() - i - 1));
        }
    }
}