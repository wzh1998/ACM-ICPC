//
//  BJUT_OJ_1087.cpp
//  ACM
//
//  Created by 王子豪 on 2017/12/4.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    int n;
    long double result = 1;
    long double current = 1;
    cin >> n;
    for(int i = 1;i <= n;i++){
        current *= i;
        result += 1 / current;
    }
    printf("%.10Lf",result);
    
    return 0;
}
