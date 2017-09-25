//
//  17_icpc_XJ_数论.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/10.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    long long int arr[1000];
    memset(arr,0,sizeof(arr));
    arr[0] = 1;
    arr[1] = 6;
    long long int n,x;
    cin >> n;
    int timer = 1;
    long long int temp,temp2;
    for(int k = 0;k < n;k++){
        scanf("%lld",&x);
        if(x == 1){
            printf("Case #%d: 1\n", timer);
            timer++;
            continue;
        }
        int i = 2;
        while(timer <= n){
            temp = arr[i - 1];
            temp2 = ((sqrt(pow(temp,2) * 8 + 1) - 1) / 2);
            if(x <= temp2){
                printf("Case #%d: %lld\n", timer,temp2);
                timer++;
                break;
            }
            else{
                arr[i] = arr[i - 1] * 6 - arr[i - 2];
                if(arr[i] < 0) {
                    printf("Case #%d: -1\n", timer);
                    break;
                }
                i++;
            }
        }
    }
    return 0;
}
