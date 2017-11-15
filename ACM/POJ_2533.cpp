//
//  POJ_2533.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/11.
//  Copyright © 2017年 王子豪. All rights reserved.
//


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int len = 0;
int dp[100000];
int arr[100000];

int main(void){
    int N;
    cin >> N;
    for(int i = 0;i < N;i++) scanf("%d",&arr[i]);
    dp[0] = arr[0];
    for(int i = 1;i < N;i++){
        if(arr[i] > dp[len]){
            len++;
            dp[len] = arr[i];
        }
        else{
            int pos = lower_bound(&dp[0],&dp[len + 1],arr[i]) - &dp[0];
            dp[pos] = arr[i];
        }
    }
    cout << len + 1 << endl;
    return 0;
}
