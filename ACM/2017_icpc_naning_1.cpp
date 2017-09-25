//
//  2017_icpc_naning_1.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/25.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
int main(void){
    double arr[1000][1000];
    int s1[10000];
    int s2[10000];
    double result_s1 = 1;
    double result_s2 = 1;
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(arr, 0, sizeof(arr));
    int lie = 1;
    char x;
    scanf("%lf",&arr[1][lie]);
    x = getchar();
    while(x != '\n'){
        lie++;
        scanf("%lf",&arr[1][lie]);
        x = getchar();
    }
    
    
    
    for(int i = 2;i <= lie;i++){
        for(int z = 1;z <= lie;z++){
            scanf("%lf",&arr[i][z]);
        }
    }
    int k_s1,k_s2,q1,q2;
    scanf("%d",&s1[0]);
    x = getchar();
    for(k_s1 = 1;x != '\n';k_s1++){
        scanf("%d",&s1[k_s1]);
        result_s1 *= arr[s1[k_s1 - 1]][s1[k_s1]];
        x = getchar();
    }
    printf("%.8lf\n",result_s1);
    
    
    
    scanf("%d",&s2[0]);
    x = getchar();
    for(k_s2 = 1;x != '\n';k_s2++){
        scanf("%d",&s2[k_s2]);
        result_s2 *= arr[s2[k_s2 - 1]][s2[k_s2]];
        x = getchar();
    }
    printf("%.8lf\n",result_s2);
    double result1 = 1;
    double result2 = 1;
    double temp1,temp2;
    scanf("%d %d",&q1,&q2);
    temp1 = arr[q1][q1];
    temp2 = arr[q2][q2];
    for(int i = 0;i < 1000;i++){
        result1 += temp1;
        result2 += temp2;
        temp1 *= arr[q1][q1];
        temp2 *= arr[q2][q2];
    }
    printf("%.8lf\n%.8lf",result1,result2);
    
    return 0;
    
}
