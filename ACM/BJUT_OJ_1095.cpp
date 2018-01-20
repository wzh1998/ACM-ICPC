//
//  BJUT_OJ_1095.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/20.
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
    int arr[20];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2;i < 15;i++){
        arr[i] = arr[i - 1] * i;
    }
    
    int temp;
    cin >> temp;
    while(temp != -1){
        for(int j = 14;j >= 0;j--){
            if(temp >= arr[j]) temp -= arr[j];
        }
        if(temp != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
        cin >> temp;
    }
    return 0;
}
