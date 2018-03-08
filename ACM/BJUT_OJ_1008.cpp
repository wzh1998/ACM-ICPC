//
//  BJUT_OJ_1008.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/8.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int solve(int n,int k){
    if(n == 0 || k == 0 || n < k) return 0;
    if(k == 1 || n == k) return 1;
    return solve(n - 1,k - 1) + solve(n - k,k);
}

int main(void){
    int n,k;
    while(~scanf("%d%d",&n,&k)) cout << solve(n,k) << endl;
    return 0;
}
