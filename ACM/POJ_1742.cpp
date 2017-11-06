//
//  POJ_1742.cpp
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

typedef struct coin{
    int value;
    int much;
}coin;

int main(void){
    int n = 1;
    int m = 1;
    coin mycoin[150000];
    int result = 0;
    int dp[150000];
    while(!(n == 0 && m == 0)){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        result = 0;
        for(int i = 0;i < n;i++) scanf("%d",&mycoin[i].value);
        for(int i = 0;i < n;i++) scanf("%d",&mycoin[i].much);
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= m;j++){
                if(dp[j] >= 0) dp[j] = mycoin[i].much;
                else if(j < mycoin[i].value || dp[j - mycoin[i].value] <= 0) dp[j] = -1;
                else dp[j] = dp[j - mycoin[i].value] - 1;
            }
        }
        for(int i = 1;i <= m;i++){
            if(dp[i] >= 0) result++;
        }
        cout << result << endl;
    }
    return 0;
}
