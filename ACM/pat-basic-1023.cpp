//
//  pat-basic-1023.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/28.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int main(void){
    char result[10000];
    int a,b,c,d,e,f,g,h,i,j;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
    
    int z = 0;
    int k;
    if(a != 0){
        if(b != 0) {
            result[z] = '1';
            b--;
            z++;
        }
        else if(c != 0) {
            result[z] = '2';
            c--;
            z++;
        }
        else if(d != 0) {
            result[z] = '3';
            d--;
            z++;
        }
        else if(e != 0) {
            result[z] = '4';
            e--;
            z++;
        }
        else if(f != 0) {
            result[z] = '5';
            f--;
            z++;
        }
        else if(g != 0) {
            result[z] = '6';
            g--;
            z++;
        }
        else if(h != 0) {
            result[z] = '7';
            h--;
            z++;
        }
        else if(i != 0) {
            result[z] = '8';
            i--;
            z++;
        }
        else if(j != 0) {
            result[z] = '9';
            j--;
            z++;
        }
        
        for(k = 0;k < a;k++,z++){
            result[z] = '0';
        }
        for(k = 0;k < b;k++,z++){
            result[z] = '1';
        }
        for(k = 0;k < c;k++,z++){
            result[z] = '2';
        }
        for(k = 0;k < d;k++,z++){
            result[z] = '3';
        }
        for(k = 0;k < e;k++,z++){
            result[z] = '4';
        }
        for(k = 0;k < f;k++,z++){
            result[z] = '5';
        }
        for(k = 0;k < g;k++,z++){
            result[z] = '6';
        }
        for(k = 0;k < h;k++,z++){
            result[z] = '7';
        }
        for(k = 0;k < i;k++,z++){
            result[z] = '8';
        }
        for(k = 0;k < j;k++,z++){
            result[z] = '9';
        }
    }
    
    else{
        for(k = 0;k < b;k++,z++){
            result[z] = '1';
        }
        for(k = 0;k < c;k++,z++){
            result[z] = '2';
        }
        for(k = 0;k < d;k++,z++){
            result[z] = '3';
        }
        for(k = 0;k < e;k++,z++){
            result[z] = '4';
        }
        for(k = 0;k < f;k++,z++){
            result[z] = '5';
        }
        for(k = 0;k < g;k++,z++){
            result[z] = '6';
        }
        for(k = 0;k < h;k++,z++){
            result[z] = '7';
        }
        for(k = 0;k < i;k++,z++){
            result[z] = '8';
        }
        for(k = 0;k < j;k++,z++){
            result[z] = '9';
        }
    }
    for(int l = 0;l < z;l++){
        cout << result[l];
    }
    
    return 0;
}
