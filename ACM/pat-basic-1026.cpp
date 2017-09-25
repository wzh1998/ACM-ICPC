//
//  pat-basic-1026.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/31.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <time.h>
#include <cmath>
using namespace std;
int main(void){
    int C1;
    int C2;
    cin >> C1 >> C2;
    int temp;
    double temp2;
    
    temp2 = C2 - C1;
    int second;
    int minute;
    int hour;
    temp2 = temp2 / 100;
    
    temp2 = round(temp2);
    temp = temp2;
    hour = temp / 3600;
    minute = (temp % 3600) / 60;
    second = temp % 60;
    printf("%02d:%02d:%02d",hour,minute,second);
    
    return 0;
}
