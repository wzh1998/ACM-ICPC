//
//  POJ_3176.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/6.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
int main(void){
    int dp[1000][1000];
    int arr[1000][1000];
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    dp[0][0] = arr[0][0];
    for(int i = 1;i < n;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0) dp[i][j] = dp[i - 1][j] + arr[i][j];
            else if(j == i) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1],dp[i - 1][j]) + arr[i][j];
        }
    }
    int max = -2147483648;
    for(int i = 0;i < n;i++) if(dp[n - 1][i] > max) max = dp[n - 1][i];
    cout << max << endl;
    
    return 0;
}
