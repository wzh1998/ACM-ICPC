//
//  BJUT_OJ_1042.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/29.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    return (b == 0) ? a : gcd(b, a % b);
}

int main(void){
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        a > b ? cout << gcd(a, b) << endl : cout << gcd(b, a) << endl;
    }
    
    return 0;
}
