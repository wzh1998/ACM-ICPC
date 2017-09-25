//
//  pat-basic-1027.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/4.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
using namespace std;
int main(void){
    int n;
    int temp = 0;
    int remain = 0;
    int sum = 0;
    int sum2 = 0;
    char x;
    cin >> n;
    cin >> x;
    int i;
    int finalx = 0;
    int final2 = 0;
    int space = 0;
    for(i = 1;sum <= n;){
        temp += i;
        sum = temp * 2 - 1;
        if(sum <= n){
            sum2 = sum;
            remain = n - sum;
            finalx = i;
        }
        i += 2;
    }
    final2 = finalx;
    while(final2 >= 1){
        for(int k = 0;k < space;k++) cout << ' ';
        for(int z = 0;z < final2;z++) cout << x;
        cout << endl;
        space ++;
        final2 -= 2;
    }
    space--;
    
    final2 = 3;
    while(final2 <= finalx){
        space--;
        for(int k = 0;k < space;k++) cout << ' ';
        for(int z = 0;z < final2;z++) cout << x;
        cout << endl;
        final2 += 2;
        
    }
    cout << remain;
    return 0;
}
