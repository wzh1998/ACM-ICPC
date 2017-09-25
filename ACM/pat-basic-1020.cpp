//
//  pat-basic-1020.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/28.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
    int N;
    int D;
    cin >> N >> D;
    double *Kucun = (double *)malloc(sizeof(double) * N);
    double *Price = (double *)malloc(sizeof(double) * N);
    int i;
    for(i = 0;i < N;i++){
        cin >> Kucun[i];
    }
    for(i = 0;i < N;i++){
        cin >> Price[i];
        Price[i] /= Kucun[i];
        //        printf("%.2f ",Price[i]);
    }
    
    int j;
    double temp;
    double temp2;
    for(i = 0;i < N - 1;i++){
        for(j = 0;j < N - 1 - i;j++){
            if(Price[j] > Price[j + 1]){
                temp2 = Price[j];
                Price[j] = Price[j + 1];
                Price[j + 1] = temp2;
                
                temp = Kucun[j];
                Kucun[j] = Kucun[j + 1];
                Kucun[j + 1] = temp;
            }
        }
    }
    
    //    for(int k = N;k >= 0;k--){
    //        printf("%.2f ",Price[k]);
    //
    //    }
    //    cout<< endl;
    //    for(int k = N;k >= 0;k--){
    //        printf("%d ",Kucun[k]);
    //
    //    }
    double remain = D;
    double total = 0;
    for(i = N - 1;remain != 0 && i >= 0;i--){
        if(remain >= Kucun[i]){
            total += Kucun[i] * Price[i];
            remain -= Kucun[i];
        }
        
        
        else{
            total += remain * Price[i];
            remain = 0;
        }
    }
    printf("%.2lf",total);
    
    return 0;
}
