//
//  2017_ICPC_GuangXi_01.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/6.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
    long long int x;
    long long i,j;
    long long int current;
    while(scanf("%lld",&x) != EOF){
        for(i = 15;i > 0;i--){
            current = 1;
            for(j = 1;j <= i;j++){
                current *= i;
            }
            if(current <= x) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
