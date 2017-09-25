//
//  pat-basic-1009.cpp
//  ACM
//
//  Created by 王子豪 on 11/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <stdio.h>

char acm[100][100];
char x,i,j,heng,shu;

int main(void){
    i = 0;
    j = 0;
    while(1){
        x = getchar();
        if(x == EOF) break;
        if(x == ' ') i++;
        else{
            acm[i][j] = x;
            j++;
        }
    }
    
    heng = j;
    shu = i;

    for(i = shu,j = 0;j <= heng;j++){
        printf("%c",acm[i][j]);
    }
    i--;
    for(;i >= 0;i--){
        printf(" ");
        for(j = 0;j <= heng;j++){
            printf("%c",acm[i][j]);
        }
    }
    
    return 0;
}
