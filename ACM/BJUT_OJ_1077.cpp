//
//  BJUT_OJ_1077.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/8.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    int T;
    int C0[100][100],C1[100][100];
    int arr[100];
    memset(C0, 0, sizeof(C0));
    memset(C1, 0, sizeof(C1));
    
    cin >> T;
    for(int i = 0;i < T;i++) scanf("%d",&arr[i]);
    for(int i = 0;i < T;i++){
        C0[i][i] = (arr[i] == 0 ? 1 : 0);
        C1[i][i] = (arr[i] == 1 ? 1 : 0);
        for(int j = i + 1;j < T;j++){
            if(arr[j] == 0){
                C0[i][j] = C0[i][j - 1] + 1;
                C1[i][j] = C1[i][j - 1];
            }
            else{
                C0[i][j] = C0[i][j - 1];
                C1[i][j] = C1[i][j - 1] + 1;
            }
        }
    }
    int max = -99999;
    int start = 0;
    int end = 0;
    
    for(int i = 0;i < T;i++){
        for(int j = i;j < T;j++){
            if(C0[i][j] - C1[i][j] > max) {
                start = i;
                end = j;
                max = C0[i][j] - C1[i][j];
            }
        }
    }
    cout << C1[0][T - 1] + max << endl;
    
    return 0;
}
