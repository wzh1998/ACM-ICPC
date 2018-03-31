//
//  LQ_完全背包.cpp
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

int dp[MAXSIZE][MAXSIZE];
int w[MAXSIZE],v[MAXSIZE];

int main(void){
    int n,bag;
    cin >> n >> bag;
    for(int i = 0;i < n;i++) scanf("%d%d",&w[i],&v[i]);
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= bag;j++){
            if(j < w[i]) dp[i + 1][j] = dp[i][j];
            else dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][bag] << endl;
    
    return 0;
}
