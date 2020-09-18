/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-09-18 13:39:00
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-09-18 13:39:02
*/
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        boolean[] mark = new boolean[10];
        for(int i = 0; i < mark.length; i++) mark[i] = false;
        while(num > 0) {
            if(!mark[num % 10]) {
                mark[num % 10] = true;
                System.out.print(num % 10);
            }
            num /= 10;
        }
        
    }
}