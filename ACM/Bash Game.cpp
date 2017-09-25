//
//  Bash Game.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/29.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10010];

int main(void){
    int k,l,i;
    
    while(scanf("%d",&k) != EOF){
        int len = 0;
        for(i = 1;i * i <= k;i++){
            a[len++] = i;
            a[len++] = k / i;
        }
        sort(a,a + len);
        int flag = 0;
        for(i = 0;i < len;i++){
            if(a[i] > 2){
                flag = 1;
                printf("%d\n",a[i] - 1);
                break;
            }
        }
        if(flag == 0) printf("0\n");
    }
    
    return 0;
}
