//
//  POJ_2385.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/8.
//  Copyright © 2017年 王子豪. All rights reserved.
//


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[10000][40];
int tree[10000];
int result;
int T,W,current,temp,temp2;

int main(void){
    
    cin >> T >> W;
    W++;
    int j = 1;
    memset(dp, 0, sizeof(dp));
    memset(tree, 0, sizeof(tree));
    cin >> temp;
    result = 0;
    tree[0] = 1;
    for(int i = 1;i < T;i++) {
        cin >> temp2;
        if(temp2 == temp){
            tree[j - 1]++ ;
        }
        else{
            tree[j]++;
            j++;
        }
        temp = temp2;
    }
    
    for(int j = 0;j < W;j++){
        dp[0][j] = tree[0];
    }
    
    dp[1][0] = tree[1];
    for(int j = 1;j < W;j++){
        dp[1][j] = dp[0][j - 1] + tree[1];
    }
    
    for(int i = 2;tree[i] != 0 && i < T;i++){
        dp[i][0] = dp[i - 2][0] + tree[i];
        for(int j = 1;j < W;j++){
            dp[i][j] = max(dp[i - 2][j],dp[i - 1][j - 1]) + tree[i];
            if(dp[i][j] > result) result = dp[i][j];
        }
    }
    
    cout << result << endl;
    
    return 0;
}

