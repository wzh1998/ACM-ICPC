//
//  pat-advance-1005.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/13.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int main(void){
    string array;
    char fin_result[1000];
    int i;
    int x;
    int temp;
    int result = 0;
    unsigned long length;
    x = getchar();
    for(i = 0;x != '\n';i++){
        x -= 48;
        array[i] = x;
        x = getchar();
    }
    length = i;
    
    for(i = 0;i < length;i++){
        result += array[i];
    }
    
    if(result == 0){
        cout << "zero";
        return 0;
    }
    for(i = 0;result >= 1;i++){
        temp = result % 10;
        fin_result[i] = temp + 48;
        result /= 10;
    }
    i--;
    for(;i>=0;i--){
        if(fin_result[i] == '0') cout << "zero";
        else if(fin_result[i] == '1') cout << "one";
        else if(fin_result[i] == '2') cout << "two";
        else if(fin_result[i] == '3') cout << "three";
        else if(fin_result[i] == '4') cout << "four";
        else if(fin_result[i] == '5') cout << "five";
        else if(fin_result[i] == '6') cout << "six";
        else if(fin_result[i] == '7') cout << "seven";
        else if(fin_result[i] == '8') cout << "eight";
        else if(fin_result[i] == '9') cout << "nine";
        if(i != 0) cout << ' ';
    }
    
    return 0;
}
