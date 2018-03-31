//
//  LQ_01背包.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/29.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXSIZE 1001

using namespace std;

long long dp[4000][500];

typedef struct item{
    long long weight;
    long long value;
}item;

item it[4000];

int main(void){
    long long n,bag;
    cin >> n >> bag;
    for(long long i = 0;i < n;i++){
        scanf("%lld %lld",&it[i].weight,&it[i].value);
    }
    
    for(long long i = n - 1;i >= 0;i--){
        for(long long j = 0;j <= bag;j++){
            if(j < it[i].weight) dp[i][j] = dp[i + 1][j];
            else dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - it[i].weight] + it[i].value);
        }
    }
    
    cout << dp[0][bag] << endl;
    
    return 0;
}
