//
//  BJUT_OJ_1100.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/31.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main(void){
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        int current_h;
        int current_m;
        int current_Total;
        scanf("%d",&current_h);
        getchar();
        scanf("%d",&current_m);
        current_Total = current_h * 60 + current_m;
        
        int sleep_h;
        int sleep_m;
        int sleep_Total;
        scanf("%d",&sleep_h);
        getchar();
        scanf("%d",&sleep_m);
        sleep_Total = sleep_h * 60 + sleep_m;
        
        int f_result;
        f_result = current_Total - sleep_Total;
        
        if(f_result < 0) f_result += 1440;
        int f_hour = f_result / 60;
        int f_minute = f_result % 60;
        printf("%02d:%02d\n",f_hour,f_minute);
    }
    
    return 0;
}
