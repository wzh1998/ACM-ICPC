//
//  pat-basic-1049.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/22.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    double arr[100003] = { 0 };
    int length;
    int i;
    double result = 0;
    cin >> length;
    for(i = 0;i < length;i++){
        scanf("%lf",&arr[i]);
        result += (double)(length - i) * (double)(i + 1) * arr[i];
    }
    printf("%.2lf",result);
    
    return 0;
}

