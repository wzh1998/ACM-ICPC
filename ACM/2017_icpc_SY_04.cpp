//
//  2017_icpc_SY_04.cpp
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
int lcs(int *num,int a){
    int len = 0;
    int lis[100100];
    memset(lis,0,sizeof(lis));
    lis[0] = num[0];
    for(int i = 1;i < a;i++){
        if(num[i] >= lis[len])
            lis[++len] = num[i];
        else{
            int pos = lower_bound(lis,lis+len,num[i]) - lis;
            lis[pos] = num[i];
        }
    }
    len += 1;
    return len;
}

int main(){
    int T;
    cin >> T;
    int num[100100];
    int num2[100100];
    memset(num, 0, sizeof(num));
    memset(num2, 0, sizeof(num2));
    int a,b,j;
    int result1,result2,resultf;
    for(int x = 0;x < T;x++){
        scanf("%d %d",&a,&b);
        for(j = 0;j < a;j++){
            scanf("%d",&num[j]);
        }
        result1 = lcs(num, a);
        
        for(int i = 0;i < a;i++){
            num2[i] = num[a - i - 1];
        }
        result2 = lcs(num2,a);
        resultf = result1 > result2 ? result1 : result2;
        resultf = a - resultf;
        if(resultf <= b){
            printf("A is a magic array.\n");
        }
        else printf("A is not a magic array.\n");
    }
    
    return 0;
}
