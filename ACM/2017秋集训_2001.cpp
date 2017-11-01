//
//  2017秋集训_2001.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;
int main(void){
    int C1,C5,C10,C50,C100,C500;
    int A;
    cin >> A;
    cin >> C1 >> C5 >> C10 >> C50 >> C100 >> C500;
    
    int remain = A;
    int coin = 0;
    
    if(remain >= 500){
        int t = remain / 500;
        if(t > C500) t = C500;
        remain -= t * 500;
        coin += t;
    }
    if(remain >= 100){
        int t = remain / 100;
        if(t > C100) t = C100;
        remain -= t * 100;
        coin += t;
    }
    if(remain >= 50){
        int t = remain / 50;
        if(t > C50) t = C50;
        remain -= t * 50;
        coin += t;
    }
    if(remain >= 10){
        int t = remain / 10;
        if(t > C10) t = C10;
        remain -= t * 10;
        coin += t;
    }
    if(remain >= 5){
        int t = remain / 5;
        if(t > C5) t = C5;
        remain -= t * 5;
        coin += t;
    }
    if(remain >= 1){
        int t = remain / 1;
        if(t > C1) t = C1;
        remain -= t * 1;
        coin += t;
    }
    cout << coin;
    
    return 0;
    
}
