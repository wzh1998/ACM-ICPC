//
//  pat-basic-1039.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/17.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;
int main(void){
    char show[1001];
    char want[1001];
    int lose;
    int i;
    int j;
    int time1 = 0;
    int time2 = 0;
    cin >> show;
    cin >> want;
    
    for(time1 = 0;want[time1] != '\0';time1++);
    for(time2 = 0;show[time2] != '\0';time2++);
    for(i = 0;i < time2;i++){
        for(j = 0;j < time1;j++){
            if(show[i] == want[j] && want[j] != '\0' && show[i] != '\0'){
                show[i] = '\0';
                want[j] = '\0';
            }
        }
    }
    bool answer = true;
    lose = 0;
    for(i = 0;i < time1;i++){
        if(want[i] != '\0'){
            answer = false;
            lose++;
        }
    }
    if(answer == true){
        cout << "Yes " << time2 - time1;
    }
    else{
        cout << "No " << lose;
    }
    
    return 0;
}
