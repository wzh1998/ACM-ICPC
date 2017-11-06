//
//  2017秋集训_P51.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/2.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
int value[100];
int weight[100];
int dparr[100][100];
int result = 0;
int W,n;
int dp(int index,int remain){
    if(dparr[index][remain] != 0){
        return dparr[index][remain];
    }
    else{
        int current = 0;
        if(index >= n) current = 0;
        else if(remain < weight[index]) current = dp(index + 1,remain);
        else current = max(dp(index + 1,remain),dp(index + 1, remain - weight[index]) + value[index]);
        dparr[index][remain] = current;
        return current;
    }
}

int main(void){
    
    cin >> n;
    memset(value, 0, sizeof(value));
    memset(weight, 0, sizeof(weight));
    memset(dparr, 0, sizeof(dparr));
    for(int i = 0;i < n;i++) scanf("%d %d",&weight[i],&value[i]);
    
    scanf("%d",&W);
    result = dp(0, W);
    cout << result;
    return 0;
}
