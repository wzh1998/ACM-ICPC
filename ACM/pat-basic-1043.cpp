//
//  pat-basic-1043.cpp
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
    char arr[10001];
    cin >> arr;
    int P = 0;
    int A = 0;
    int T = 0;
    int e = 0;
    int s = 0;
    int t = 0;
    int i;
    for(i = 0;i < 10001 && arr[i] != '\0';i++){
        if(arr[i] == 'P') P++;
        else if(arr[i] == 'A') A++;
        else if(arr[i] == 'T') T++;
        else if(arr[i] == 'e') e++;
        else if(arr[i] == 's') s++;
        else if(arr[i] == 't') t++;
    }
    while(!(P == 0 && A == 0 && T == 0 && e == 0 && s == 0 && t == 0)){
        if(P > 0){
            cout << 'P';
            P--;
        }
        if(A > 0){
            cout << 'A';
            A--;
        }
        if(T > 0){
            cout << 'T';
            T--;
        }
        if(e > 0){
            cout << 'e';
            e--;
        }
        if(s > 0){
            cout << 's';
            s--;
        }
        if(t > 0){
            cout << 't';
            t--;
        }
    }
    
    
    return 0;
}
