//
//  pat-basic-1012.cpp
//  ACM
//
//  Created by 王子豪 on 12/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int main(void){
    int n,temp,x2,x4;
    int A1,A2,A3,A5;
    int B1,B2,B3,B4,B5;
    double A4;
    A1 = 0;
    A2 = 0;
    A3 = 0;
    A4 = 0;
    A5 = -2147483648;
    x2 = 0;
    x4 = 0;
    cin >> n;
    B1 = 0;
    B2 = 0;
    B3 = 0;
    B4 = 0;
    B5 = 0;
    for(int i = 0;i < n;i++){
        cin >> temp;
        if(temp % 10 == 0){
            A1 += temp;
            B1++;
        }
        else if(temp % 5 == 1){
            if(x2 % 2 == 0){
                A2 += temp;
                x2 = 1;
            }
            else{
                A2 -= temp;
                x2 = 0;
            }
            B2++;
        }
        else if(temp % 5 == 2){
            A3 += 1;
            B3++;
        }
        else if(temp % 5 == 3){
            A4 += temp;
            x4 += 1;
            B4++;
        }
        else if(temp % 5 == 4){
            if(temp > A5){
                A5 = temp;
            }
            B5++;
        }
    }
    A4 /= x4;
    
    if( B1 != 0 ){
        printf("%d ",A1);
    }
    else{
        printf("N ");
    }
    if( B2 != 0 ){
        printf("%d ",A2);
    }
    else{
        printf("N ");
    }
    if( B3 != 0 ){
        printf("%d ",A3);
    }
    else{
        printf("N ");
    }
    if( B4 != 0 ){
        printf("%.1lf ",A4);
    }
    else{
        printf("N ");
    }
    if( B5 != 0 ){
        printf("%d",A5);
    }
    else{
        printf("N");
    }
    return 0;
}
