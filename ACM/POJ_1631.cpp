//
//  POJ_1631.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/9.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;


int mybridge[100000];
int dp[100000];
int main(void){
    int t;
    cin >> t;
    for(int z = 0;z < t;z++){
        //        memset(dp, 0, sizeof(dp));
        //        memset(mybridge, 0, sizeof(mybridge));
        int p;
        scanf("%d",&p);
        for(int i = 0;i < p;i++){
            scanf("%d",&mybridge[i]);
        }
        int len = 0;
        dp[0] = mybridge[0];
        for(int i = 0;i < p;i++){
            if(mybridge[i] > dp[len]){
                len++;
                dp[len] = mybridge[i];
            }
            else{
                int pos = lower_bound(&dp[0], &dp[len + 1], mybridge[i]) - &dp[0];
                dp[pos] = mybridge[i];
            }
        }
        
        cout << len + 1 << endl;
    }
    return 0;
}
