//
//  BJUT_OJ_1075.cpp
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

int arr[10][10];

int main(void){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        arr[0][i] = 1;
        arr[i][0] = 1;
    }
    for(int i = 1;i < n;i++){
        for(int j = 1;j < n;j++){
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    cout << arr[n - 1][n - 1] << endl;
    
    return 0;
}
