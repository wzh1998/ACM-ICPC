//
//  POJ_2456.cpp
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

int N,M;
int arr[110000];
const long long int INF = 1000000002;
bool judge(long long int distance){
    long long int current = 0;
    for(int i = 1;i < M;i++){
        long long int temp = current + 1;
        while(temp < N && arr[temp] - arr[current] < distance) temp++;
        if(temp == N) return false;
        else current = temp;
    }
    return true;
}

int main(void){
    cin >> N >> M;
    for(int i = 0;i < N;i++) scanf("%d",&arr[i]);
    sort(&arr[0], &arr[N]);
    long long int lb = 0;
    long long int ub = INF;
    while(ub - lb > 1){
        long long int mid = lb + ((ub - lb) / 2);
        if(judge(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb;
}
