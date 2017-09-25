//
//  pat-basic-1033.cpp
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
    bool temp = true;
    bool caps = true;
    char array[100001];
    char damaged[100001];
    char result[100001];
    int z = 0;
    int k = 0;
    char x;
    while((x = getchar()) != '\n'){
        damaged[k] = x;
        k++;
    }
    scanf("%s",array);
    for(int z = 0;damaged[z] != '\0';z++){
        if(damaged[z] == '+') caps = false;
    }
    for(int i = 0;array[i] != '\0';i++){
        temp = true;
        if(array[i] >= 'A' && array[i] <= 'Z' && caps == false) temp = false;
        for(int j = 0;damaged[j] != '\0';j++){
            if(damaged[j] == array[i]) temp = false;
            if(damaged[j] >= 'A' && damaged[j] <= 'Z' && array[i] == damaged[j] + 32) temp = false;
            //            if(damaged[j] >= 'a' && damaged[j] <= 'z' && array[i] == damaged[j] - 32) temp = false;
        }
        if(temp == true){
            result[z] = array[i];
            z++;
        }
    }
    if(result[0] != '\0') printf("%s",result);
    
    return 0;
}
