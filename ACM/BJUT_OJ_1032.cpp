//
//  BJUT_OJ_1032.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/22.
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
    int N;
    long long int arr[110000];
    
    cin >> N;
    for(int i = 0;i < N;i++) scanf("%lld",&arr[i]);
    
    bool mark = true;
    long long int max1 = -9223372036854775808;
    
    for(int i = 0;i < N;i++){
        if(arr[i] > 0) mark = false;
        if(arr[i] > max1) max1 = arr[i];
    }
    if(mark) {
        cout << max1 << endl;
        return 0;
    }
    
    
    long long int currentsum = 0;
    long long int maxn = -9223372036854775808;
    for(int i = 0;i < N;i++){
        currentsum += arr[i];
        
        if(currentsum < 0) currentsum = 0;
        if(currentsum > maxn) maxn = currentsum;
    }
    cout << maxn << endl;
    return 0;
}
