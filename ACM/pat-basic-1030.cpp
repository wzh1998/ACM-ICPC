//
//  pat-basic-1030.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/4.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void){
    long long int n,p,maxn,minn,answer,i,fin_ans;
    long long int arr[100001] = { -1 };
    maxn = -2147483648;
    minn = 2147483647;
    answer = 0;
    fin_ans = 0;
    int first = 0;
    int last = 0;
    cin >> n >> p;
    for(i = 0;i < n;i++) cin >> arr[i];
    sort(&arr[0], &arr[n]);
    
    while(last < n){
        maxn = arr[last];
        minn = arr[first];
        if(maxn <= minn * p){
            last ++;
            answer ++;
        }
        else{
            first ++;
            answer --;
        }
        
        if(answer > fin_ans) fin_ans = answer;
    }
    
    cout << fin_ans;
    return 0;
}
