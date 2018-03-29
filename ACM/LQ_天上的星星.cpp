//
//  LQ_天上的星星.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/29.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <math.h>

#define MAXSIZE 3001
#define INF 9999999

using namespace std;

long long dp[MAXSIZE][MAXSIZE];

int main(void){
    long long n;
    cin >> n;
    for(long long i = 0;i < n;i++){
        long long x,y,value;
        scanf("%lld%lld%lld",&x,&y,&value);
        x++;
        y++;
        dp[x][y] += value;
    }
    
    for(long long i = 1;i < MAXSIZE;i++){
        for(long long j = 1;j < MAXSIZE;j++){
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    
    long long T;
    cin >> T;
    
    
    for(long long i = 0; i < T;i++){
        long long a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        ++a;
        ++b;
        ++c;
        ++d;
        cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << endl;
    }
    
    return 0;
}
