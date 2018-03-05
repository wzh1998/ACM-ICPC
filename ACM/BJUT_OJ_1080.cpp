//
//  BJUT_OJ_1080.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/5.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main(void){
    long long T;
    long long arr[500001];
    long long sum[500001];
    long long result = 0;
    cin >> T;
    for(long long i = 0;i < T;i++) scanf("%lld",&arr[i]);
    
    if(T < 3){
        cout << 0;
        return 0;
    }
    sum[0] = arr[0];
    for(long long i = 1;i < T;i++){
        sum[i] = sum[i - 1] + arr[i];
    }
    
    if(sum[T - 1] % 3 != 0) {
        cout << 0;
        return 0;
    }
    
    if(sum[T - 1] == 0){
        long long counter = 0;
        for(long long k = T - 1;k >= 0;k--){
            if(sum[k] == 0) counter++;
            
        }
        long long temp = (counter - 1) * (counter - 2) / 2;
        cout << temp;
        return 0;
    }
    long long level_1 = sum[T - 1] / 3;
    long long level_2 = 2 * level_1;
    
    long long counter_l2 = 0;
    
    for(long long i = T - 1;i >= 0;i--){
        if(sum[i] == level_2) counter_l2++;
        else if(sum[i] == level_1) result += counter_l2;
    }
    cout << result;
    
    return 0;
}
