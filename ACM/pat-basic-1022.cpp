//
//  pat-basic-1021.cpp
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
    
    int A;
    int B;
    cin >> A >> B;
    int jinzhi;
    char result[100000];
    cin >> jinzhi;
    long int temp = A + B;
    int i = 0;
    if(temp == 0){
        cout << '0';
        return 0;
    }
    while(temp != 0){
        result[i] = (temp % jinzhi) + 48;
        temp /= jinzhi;
        i++;
    }
    i--;
    for(;i >= 0;i--){
        cout << result[i];
    }
    return 0;
}
