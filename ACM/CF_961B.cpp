//
//  CF_961B.cpp
//  ACM
//
//  Created by 王子豪 on 2018/4/10.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAXSIZE 1000000

using namespace std;

long long arr[MAXSIZE];
long long num[MAXSIZE];
long long sum[MAXSIZE];
long long res = 0;
long long maxn = 0;
int main(void){
    long long n,k;
    cin >> n >> k;
    for(long long i = 0;i < n;i++) scanf("%lld",&arr[i]);
    for(long long i = 0;i < n;i++){
        scanf("%lld",&num[i]);
        res += num[i] == 1 ? arr[i] : 0;
    }
    
    sum[0] = num[0] == 0 ? arr[0] : 0;
    for(long long i = 1;i < n;i++) sum[i] = num[i] == 0 ? sum[i - 1] + arr[i] : sum[i - 1];
    for(long long i = k - 1;i < n;i++) {
        long long temp = sum[i] - sum[i - k];
        if(temp > maxn) maxn = temp;
    }
    res += maxn;
    cout << res << endl;
    
    return 0;
}
