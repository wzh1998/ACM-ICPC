//
//  pat-basic-1013.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/22.
//  Copyright © 2017年 王子豪. All rights reserved.
//
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
using namespace std;

int main(void){
    char A[100100] = { 'A' };
    char B[100100] = { 'A' };
    char DA;
    char DB;
    string R_A;
    string R_B;
    
    cin >> A;
    cin >> DA;
    cin >> B;
    cin >> DB;
    
    int i;
    int timer = 0;
    for(i = 0;A[i] != 'A';i++){
        if(A[i] == DA){
            timer++;
        }
        i++;
    }
    for(i = 0;i <= timer;i++){
        R_A[i] = DA;
    }
    
    int x1;
    x1 = atoi(R_A.c_str());
    
    timer = 0;
    for(i = 0;B[i] != 'A';i++){
        if(B[i] == DB){
            timer++;
        }
        i++;
    }
    for(i = 0;i <= timer;i++){
        R_B[i] = DB;
    }
    
    int x2;
    x2 = atoi(R_B.c_str());
    cout << x1 << endl;
    cout << x2;
//    cout << x1 + x2;
}
