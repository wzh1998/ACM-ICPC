//
//  pat-basic-1040.cpp
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
    char array[100001];
    scanf("%s",array);
    int i;
    int length = 0;
    int num_T,num_AT,num_PAT;
    
    num_T = 0;
    num_AT = 0;
    num_PAT = 0;
    
    
    for(i = 0;array[i] != '\0';i++)
        length++;
    
    for(i = length - 1;i >= 0;i--){
        if(array[i] == 'T'){
            num_T++;
        }
        else if(array[i] == 'A'){
            num_AT += num_T;
            num_AT %= 1000000007;
        }
        else if(array[i] == 'P'){
            num_PAT += num_AT;
            num_PAT %= 1000000007;
        }
    }
    
    cout << num_PAT;
    return 0;
}
