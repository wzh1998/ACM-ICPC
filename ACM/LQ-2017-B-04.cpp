//
//  LQ-2017-B-04.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/18.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>


using namespace std;

int main(void){
    
    //    double answer = 2086458231 / 3.8863313030;
    //    answer *= 135.3494686335;
    double arr[30][30];
    memset(arr, 0, sizeof(arr));
    for(int i = 0;i < 29;i++){
        for(int j = 0;j < i + 1;j++) scanf("%lf",&arr[i][j]);
    }
    
    for(int i = 0;i < 29;i++){
        for(int j = 0;j < i + 1;j++){
            double temp = arr[i][j] / 2.0;
            arr[i + 1][j] += temp;
            arr[i + 1][j + 1] += temp;
        }
    }
    
    for(int i = 0;i < 30;i++) printf("%.10lf\n",arr[29][i]);
    
    return 0;
}

