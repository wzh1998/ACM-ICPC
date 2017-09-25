//
//  pat-basic-1042.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/18.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    
    int result[200] ={ 0 };
    int max = -1;
    int character = '\0';
    int i;
    int x;
    
    x = getchar();
    i = 0;
    
    while(x != '\n'){
        if(x >= 65 && x <= 90){
            x += 32;
        }
        result[x]++;
        x = getchar();
    }
    for( i = 97;i <= 122;i++){
        if(result[i] > max){
            max = result[i];
            character = i;
        }
    }
    
    printf("%c %d",character,max);
    
    return 0;
}
