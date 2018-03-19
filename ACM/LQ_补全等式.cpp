//
//  LQ_补全等式.cpp
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
int visit[14];
int a[14];
void fuc(int step){
    if(step == 10){
        int result1 = a[0] * a[1] + a[2] * a[3];
        int result2 = a[5] * a[6] - a[7] * a[8];
        if((result1 % a[4] == 0) && (result2 % a[9] == 0)){
            int x1 = result1 / a[4];
            int x2 = result2 / a[9];
            if(x1 >= 1 && x1 <= 13 && x2 >= 1 && x2 <= 13 && x1 != x2 && visit[x1] != 1 && visit[x2] != 1) res++;
        }
        return;
    }
    
    for(int i = 1;i <= 13;i++){
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

