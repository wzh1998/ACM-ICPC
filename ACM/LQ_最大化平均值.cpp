//
//  LQ_最大化平均值.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/31.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAXSIZE 20

using namespace std;

double v[MAXSIZE];
double w[MAXSIZE];
double y[MAXSIZE];
int n,K;

bool solve(double x){
    double res = 0;
    for(int i = 0;i < n;i++){
        y[i] = v[i] - w[i] * x;
    }
    sort(y,y + n);
    for(int i = 0;i < K;i++){
        res += y[n - i - 1];
    }
    
    return res >= 0;
}

int main(void){
    
    cin >> n >> K;
    for(int i = 0;i < n;i++) cin >> v[i] >> w[i];
    double lb = 0;
    double ub = 10000;
    for(int i = 0;i < 100;i++){
        double mid = (lb + ub) / 2.0;
        if(solve(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb << endl;
    
    return 0;
}
