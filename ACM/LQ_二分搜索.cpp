//
//  LQ_二分搜索.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/31.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef struct cho{
    int H;
    int W;
}cho;
cho mc[110000];

int N,K;

bool solve(int len){
    int num = 0;
    for(int i = 0;i < N;i++){
        int x = mc[i].H / len;
        int y = mc[i].W / len;
        num += x * y;
    }
    return num >= K;
}

int main(void){
    cin >> N >> K;
    for(int i = 0;i < N;i++){
        scanf("%d%d",&mc[i].H,&mc[i].W);
    }
    int lb = 1;
    int ub = 100000;
    int mid = 0;
    while(lb < (ub - 1)){
        mid = lb + ((ub - lb) >> 1);
        if(solve(mid)) lb = mid;
        else ub = mid;
    }
    
    
    cout << lb << endl;
    
    return 0;
}

