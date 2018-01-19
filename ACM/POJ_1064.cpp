//
//  POJ_1064.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/19.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N,K;
double arr[100000];

bool judge(double x){
    int num = 0;
    for(int i = 0;i < N;i++){
        num += (int) (arr[i] / x);
        if(num >= K) return true;
    }
    return num >= K;
}
int main(void){
    cin >> N >> K;
    for(int i = 0;i < N;i++) scanf("%lf",&arr[i]);
    
    double lb = 0;
    double ub = 10000000;
    for(int i = 0;i < 100;i++){
        double mid = (ub + lb) / 2.0;
        if(judge(mid)) lb = mid;
        else ub = mid;
    }
    printf("%.2f\n",floor(lb * 100) / 100);
    
    return 0;
}
