//
//  pat-basic-1041.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/18.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>

using namespace std;

typedef struct ide{
    char id[15];
    int ini;
    int fin;
}ide;
int main(void){
    int n;
    cin >> n;
    char arr[1001][14] = { '\0' };
    int ini[1001];
    int fin[1001];
    memset(ini, -1, sizeof(int) * 1000);
    memset(fin, -1, sizeof(int) * 1000);
    int i;
    for(i = 0;i < n;i++){
        cin >> arr[i];
        scanf("%d",&ini[i]);
        scanf("%d",&fin[i]);
    }
    
    int m,k;
    int temp;
    int x;
    cin >> m;
    
    for(i = 0;i < m;i++){
        scanf("%d",&temp);
        for(k = 0;k < n ;k++){
            if(ini[k] == temp){
                for(x = 0;x < 14;x++) cout << arr[k][x];
                printf(" %d\n",fin[k]);
            }
        }
    }
    
    return 0;
}
