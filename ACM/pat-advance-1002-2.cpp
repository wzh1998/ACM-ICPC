//
//  pat-advance-1002-2.cpp
//  ACM
//
//  Created by 王子豪 on 08/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <stdio.h>

const double EPS = 2e-52;

int main(void){
    double ARR1[1001] = {0};
    double ARR2[1001] = {0};
    double RESULT[1001] = {0};
    int i,x;
    scanf("%d",&i);
    while(i--){
        scanf("%d",&x);
        scanf("%lf",&ARR1[x]);
    }
    scanf("%d",&i);
    while(i--){
        scanf("%d",&x);
        scanf("%lf",&ARR2[x]);
    }
    
    int timer = 0;
    for(i = 0;i < 1001;i++){
        if(!(ARR1[i] <= EPS && ARR1[i] >= -EPS) || !(ARR2[i] <= EPS && ARR2[i] >= -EPS)){
            RESULT[i] = ARR1[i] + ARR2[i];
        }
    }
    for(i = 0;i < 1001;i++){
        if(!(RESULT[i] <= EPS && RESULT[i] >= -EPS))
            timer++;
    //    printf("<%d>",timer);
    }
    
    printf("%d",timer);
    for(i = 1000;i >= 0;i--){
        if(!(RESULT[i] <= EPS && RESULT[i] >= -EPS)){
            printf(" %d %.1lf",i,RESULT[i]);
        }
    }
    
    return 0;
}
