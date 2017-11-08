//
//  POJ_1065.cpp
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
typedef struct tree{
    int length;
    int weight;
}tree;

bool compare1(tree a,tree b){
    if(a.length != b.length) return a.length >= b.length;
    else return a.weight >= b.weight;
}
bool compare2(tree a,tree b){
    if(a.weight != b.weight) return a.weight >= b.weight;
    else return a.length >= b.length;
}
int T,n,result1,result2,len;
int dp[100100];
tree mytree[100100];

int main(void){
    cin >> T;
    for(int z = 0;z < T;z++){
        cin >> n;
        len = 0;
        memset(dp, 0, sizeof(dp));
        memset(mytree, 0, sizeof(tree));
        for(int i = 0;i < n;i++) scanf("%d %d",&mytree[i].length,&mytree[i].weight);
        sort(&mytree[0], &mytree[n], compare1);
        
        
        
        dp[0] = mytree[0].weight;
        for(int i = 1;i < n;i++){
            if(mytree[i].weight > dp[len]){
                len++;
                dp[len] = mytree[i].weight;
            }
            else{
                int pos = lower_bound(dp, dp + len, mytree[i].weight) - &dp[0];
                dp[pos] = mytree[i].weight;
            }
        }
        result1 = len + 1;
        
        len = 0;
        memset(dp, 0, sizeof(dp));
        sort(&mytree[0], &mytree[n], compare2);
        
        
        dp[0] = mytree[0].length;
        for(int i = 1;i < n;i++){
            if(mytree[i].length > dp[len]){
                len++;
                dp[len] = mytree[i].length;
            }
            else{
                int pos = lower_bound(dp, dp + len, mytree[i].length) - &dp[0];
                dp[pos] = mytree[i].length;
            }
        }
        result2 = len + 1;
        
        cout << ((result1 < result2)?result1:result2) << endl;
    }
    return 0;
}

