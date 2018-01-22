//
//  BJUT_OJ_1022.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/21.
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
    int p1x,p1y;
    int p2x,p2y;
    int p3x,p3y;
    int p4x,p4y;
    double arr[10];
    for(int i = 0;i < T;i++){
        cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y >> p4x >> p4y;
        arr[0] = sqrt(pow(p1x - p2x,2) + pow(p1y - p2y,2));
        arr[1] = sqrt(pow(p1x - p3x,2) + pow(p1y - p3y,2));
        arr[2] = sqrt(pow(p1x - p4x,2) + pow(p1y - p4y,2));
        arr[3] = sqrt(pow(p2x - p3x,2) + pow(p2y - p3y,2));
        arr[4] = sqrt(pow(p2x - p4x,2) + pow(p2y - p4y,2));
        arr[5] = sqrt(pow(p3x - p4x,2) + pow(p3y - p4y,2));
        
        
        for(int j = 0;j < 6;j++){
            arr[j] = floor(arr[j] * 100) / 100;
        }
        sort(&arr[0], &arr[6]);
        
        
        if(arr[4] == arr[5] && arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] && arr[0] != arr[4]) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}

