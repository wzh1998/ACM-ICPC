//
//  POJ_3061.cpp
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

int arr[100000];

int main(void){
    int T;
    cin >> T;
    for(int j = 0;j < T;j++){
        int N,S;
        cin >> N >> S;
        for(int i = 0;i < N;i++) scanf("%d",&arr[i]);
        int re_ans = N + 1;
        int lb = 0;
        int ub = 0;
        int sum = 0;
        while(true){
            while(ub < N && sum < S){
                sum += arr[ub];
                ub++;
            }
            if(sum < S) break;
            re_ans = min(re_ans,ub - lb);
            sum -= arr[lb++];
        }
        if(re_ans == N + 1) printf("0\n");
        else printf("%d\n",re_ans);
    }
    
    return 0;
}
