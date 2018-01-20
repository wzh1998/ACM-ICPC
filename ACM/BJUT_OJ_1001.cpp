//
//  BJUT__OJ_1001.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/20.
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

int arr[200000];

int main(void){
    int N,K;
    while(true){
        cin >> N >> K;
        if(N == 0 && K == 0) return 0;
        for(int i = 0; i < N;i++) scanf("%d",&arr[i]);
        int lb = 0;
        int ub = 0;
        int sum = 0;
        int result = -1;
        while(true){
            while(ub < N && sum < K){
                sum += arr[ub];
                ub++;
            }
            if(sum > K){
                ub--;
                sum -= arr[ub];
            }
            result = max(result,ub - lb);
            if(ub >= N) break;
            sum -= arr[lb++];
        }
        if(result == -1) cout << "0" << endl;
        else cout << result << endl;
    }
    return 0;
}
