//
//  LQ-PREV-21.cpp
//  ACM
//
//  Created by 王子豪 on 2017/12/20.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>


using namespace std;
bool is_want1(int x,int want){
    char arr[10];
    sprintf(arr, "%d",x);
    if(((arr[0] - '0') * 2 + (arr[1] - '0') * 2 + (arr[2] - '0')) == want) return true;
    
    return false;
}
bool is_want2(int x,int want){
    char arr[10];
    sprintf(arr, "%d",x);
    if((arr[0] - '0' + arr[1] - '0' + arr[2] - '0') * 2 == want) return true;
    return false;
}
int main(void){
    int n;
    cin >> n;
    bool has = false;
    for(int i = 100;i <= 999;i++){
        if(is_want1(i,n)){
            char arr[10];
            sprintf(arr, "%d",i);
            cout << arr[0] << arr[1] << arr[2] << arr[1] << arr[0] << endl;
            has = true;
        }
    }
    for(int i = 100;i <= 999;i++){
        if(is_want2(i,n)){
            char arr[10];
            sprintf(arr, "%d",i);
            cout << arr[0] << arr[1] << arr[2] << arr[2] << arr[1] << arr[0] << endl;
            has = true;
        }
        
    }
    if(has == false) cout << -1 << endl;
    return 0;
}

