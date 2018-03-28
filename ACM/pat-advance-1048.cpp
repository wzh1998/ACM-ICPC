//
//  pat-advance-1048.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/27.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <math.h>
#define MAXSIZE 100000

int arr[MAXSIZE];

using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    for(int i = 0;i < N;i++) {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    bool mark = false;
    
    for(int i = 0;i < MAXSIZE;i++){
        if(arr[i] && arr[M - i]) {
            if((i != M - i) || (i == M - i && arr[i] > 1)){
                mark = true;
                cout << i << " " << M - i << endl;
                break;
            }
        }
    }
    if(!mark) cout << "No Solution" << endl;
    
    return 0;
}
