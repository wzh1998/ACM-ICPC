//
//  BJUT_OJ_1094.cpp
//  ACM
//
//  Created by 王子豪 on 2017/12/8.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
long long int arr[1000100];
long long int dp[1000100];

int main(void){
    long long int k;
    scanf("%lld",&k);
    
    //    sort(&arr[0],&arr[k]);
    long long int current = 0;
    for(long long int i = 0;i < k;i++){
        scanf("%lld",&arr[i]);
        current += arr[i];
        dp[i] = current;
    }
    long long int q,tq;
    scanf("%lld",&q);
    for(long long int i = 0;i < q;i++){
        scanf("%lld",&tq);
        if(tq >= dp[k - 1]) printf("%lld\n",k);
        else if(tq < dp[0]) printf("0\n");
        else if(tq == dp[0]) printf("1\n");
        else{
            long long int position = upper_bound(&dp[0], &dp[k], tq) - &dp[0];
            //            if(dp[position] == tq) printf("%d\n",position + 1);
            printf("%lld\n",position);
        }
    }
    return 0;
}
