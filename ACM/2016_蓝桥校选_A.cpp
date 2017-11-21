//
//  2016_蓝桥校选_A.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/21.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;
bool is_lucky(long long int x){
    long long int temp = x;
    if(x == 0) return false;
    while(temp > 0){
        int remain = temp % 10;
        if(remain != 4 && remain != 7) return false;
        temp /= 10;
    }
    return true;
}


int main(void){
    char temp;
    long long int count = 0;
    scanf("%c",&temp);
    while(temp != '\n'){
        if(temp == '4' || temp == '7') count++;
        scanf("%c",&temp);
    }
    is_lucky(count) ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}
