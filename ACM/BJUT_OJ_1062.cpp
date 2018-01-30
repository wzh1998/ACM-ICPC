//
//  BJUT_OJ_1062.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/30.
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
        double arr[10];
        for(int j = 0;j < 10;j++) scanf("%lf",&arr[j]);
        int result = 0;
        for(int j = 0;j < 9;j++){
            if(!(abs(arr[j]) < 0.000001)) result++;
        }
        if(result == 0){
            printf("0.000\n");
            continue;
        }
        int counter = 0;
        for(int j = 0;j < 9;j++){
            if(!(abs(arr[j]) < 0.000001)){
                double xishu = arr[j] * (9 - j);
                int mi = 8 - j;
                if(xishu != 1.0 || j == 8) printf("%.3lf",xishu);
                if(mi != 0) {
                    printf("x");
                    if(mi != 1) printf("^%d",mi);
                }
                if(counter < result - 1) printf("+");
                counter++;
            }
        }
        cout << endl;
    }
    
    return 0;
}
