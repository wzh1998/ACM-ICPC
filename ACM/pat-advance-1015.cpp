//
//  pat-advance-1015.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/5.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
bool is_prime(int a){
    int i;
    if( a == 0 || a == 1) return false;
    for(i = 2;i <= floor(sqrt(a) + 0.5);i++){
        if(a % i == 0) return false;
    }
    return true;
}
void itoa_my(int value,char *stringa,int radix)
{
    int i = 0;
    int temp = value;
    while(temp != 0){
        stringa[i] = (temp % radix) + 48;
        temp /= radix;
        i++;
    }
    
}

int main(void){
    int num;
    int radix;
    int i,j;
    char trans[100] = { '\0' };
    int trans2;
    scanf("%d",&num);
    while(num >= 0){
        trans2 = 0;
        scanf("%d",&radix);
        itoa_my(num, trans, radix);
        for(i = 99,j = 0;i >= 0;i--){
            if(trans[i] >= '0' && trans[i] <= '9'){
                trans2 += pow(radix,j) * (trans[i] - 48);
                j++;
            }
        }
        if( is_prime(num) && is_prime(trans2)) printf("Yes\n");
        else printf("No\n");
        memset(trans,'\0', sizeof(char) * 100);
        scanf("%d",&num);
    }
    
    return 0;
}
