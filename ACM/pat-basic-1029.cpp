//
//  pat-basic-1029.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
using namespace std;
int main(void){
    char input[100] = {'\0'};
    char output[100] = {'\0'};
    char result[100] = {'\0'};
    char temp;
    bool temp2;
    scanf("%s",input);
    scanf("%s",output);
    int i,j,z;
    for(i = 0,j = 0; input[i] != '\0';){
        if( input[i] == output[j] ){
            i++;
            j++;
            continue;
        }
        else{
            temp = input[i];
            temp2 = true;
            if(temp >= 97 && temp <= 122){
                temp -= 32;
            }
            for(z = 0;result[z] != '\0';z++){
                if(temp == result[z]){
                    temp2 = false;
                    break;
                }
            }
            if(temp2 == true){
                result[z] = temp;
            }
            i++;
        }
    }
    for(z = 0;result[z] != '\0';z++){
        cout << result[z];
    }
    
    return 0;
}
