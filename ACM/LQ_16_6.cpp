//
//  LQ_16_6.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/31.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int visit[20];
int buf[20];


int dfs(int t){
    if(t == 3){
        bool a1 = (buf[0] + buf[1] == buf[2]);
        if(!a1) return 0;
    }
    if(t == 6){
        bool a2 = (buf[3] - buf[4] == buf[5]);
        if(!a2) return 0;
    }
    if(t == 9){
        bool a3 = (buf[6] * buf[7] == buf[8]);
        if(!a3) return 0;
    }
    if(t == 12){
        bool a4 = (buf[9] * buf[10] == buf[11]);
        if(a4) return 1;
        else return 0;
    }
    
    int res = 0;
    for(int i = 0;i < 13;i++){
        if(!visit[i]){
            visit[i] = 1;
            buf[t] = i + 1;
            
            res += dfs(t + 1);
            
            visit[i] = 0;
            buf[t] = 0;
        }
    }
    
    return res;
}


int main(void){
    cout << dfs(0) << endl;
    
    
    return 0;
}
