//
//  LQ_划分整数.cpp
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

long long dp[MAXSIZE][MAXSIZE];

long long solve(int n,int k){
    if(n == k || k == 1) return 1;
    if(n == 0 || k == 0 || (k > n)) return 0;
    
    dp[n - 1][k - 1] = dp[n - 1][k - 1] == 0 ? solve(n - 1,k - 1) : dp[n - 1][k - 1];
    dp[n - k][k] = dp[n - k][k] == 0 ? solve(n - k, k) : dp[n - k][k];
    
    return dp[n - 1][k - 1] + dp[n - k][k];
}

int main(void){
    int n,k;
    cin >> n >> k;
    long long res = 0;
    for(int i = 1;i <= k;i++)
        res += solve(n, i);
    cout << res << endl;
    return 0;
}
