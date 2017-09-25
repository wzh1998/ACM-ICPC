
//
//  pat-basic-1047.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/21.
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
    int n;
    cin >> n;
    int team[1001] = { 0 };
    int i,result;
    int temp1,temp2,temp3;
    int max = -1;
    result = 0;
    for(i = 0;i < n;i++){
        scanf("%d %d %d",&temp1,&temp2,&temp3);
        team[temp1] += temp3;
    }
    
    
    for(i = 0;i < 1001;i++){
        if(team[i] > max){
            max = team[i];
            result = i;
        }
    }
    
    cout << result << ' ' << max;
    
    return 0;
}
