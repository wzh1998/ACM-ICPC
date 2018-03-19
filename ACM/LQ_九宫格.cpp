//
//  LQ_九宫格.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/15.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int res = 0;
int visit[10];
int a[10];
void fuc(int step){
    if(step == 9){
        if(a[0] + a[1] + a[2] == 15 && a[3] + a[4] + a[5] == 15 && a[6] + a[7] + a[8] == 15 && a[0] + a[3] + a[6] == 15 && a[1] + a[4] + a[7] == 15 && a[2] + a[5] + a[8] == 15) res++;
        return;
    }
    
    for(int i = 1;i <= 9;i++){
        if(!visit[i]){
            visit[i] = 1;
            a[step] = i;
            fuc(step + 1);
            visit[i] = 0;
            a[step] = 0;
        }
    }
}

int main(void){
    fuc(0);
    cout << res << endl;
    
    return 0;
}
