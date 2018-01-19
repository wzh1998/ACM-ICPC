//
//  pat-basic-1060.cpp
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
#include <cmath>
using namespace std;


int main(void){
    int arr[110000];
    memset(arr,0,sizeof(arr));
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        cin >> arr[i];
    }
    sort(&arr[0], &arr[T]);
    int counter = 0;
    if(T == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0;i < T;i++){
        if(arr[T - 1 - i] > counter + 1) counter++;
        else break;
    }
    
    cout << counter << endl;
    
    return 0;
}
