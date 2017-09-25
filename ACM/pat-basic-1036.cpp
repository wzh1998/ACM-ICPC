//
//  pat-basic-1036.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/14.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main(void){
    int n;
    char x;
    int i;
    int z;
    cin >> n >> x;
    for(i = 1;i <= (n + 1) / 2;i++){
        if(i == 1){
            for(z = 0;z < n;z++){
                printf("%c",x);
            }
            printf("\n");
        }
        else if(i > 1 && i < (n + 1) / 2){
            printf("%c",x);
            for(z = 1;z < n - 1;z++){
                printf(" ");
            }
            printf("%c",x);
            printf("\n");
        }
        else if(i == (n + 1) / 2){
            for(z = 0;z < n;z++){
                printf("%c",x);
            }
            printf("\n");
        }
    }
    
    
    return 0;
}
