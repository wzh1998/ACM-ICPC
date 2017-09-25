//
//  pat-basic-1037.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/17.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>

using namespace std;
int main(void){
    int S,G,K;
    int S_p,G_p,K_p;
    char temp[100] = {'\0'};
    char temp2 = '\0';
    int i;
    i = 0;
    while((temp2 = getchar()) != '.'){
        temp[i] = temp2;
        i++;
    }
    
    
    
    G = atoi(temp);
    temp2 = '\0';
    memset(temp, '\0', sizeof(char) * 100);
    i = 0;
    while((temp2 = getchar()) != '.'){
        temp[i] = temp2;
        i++;
    }
    S = atoi(temp);
    
    //
    temp2 = '\0';
    memset(temp, '\0', sizeof(char) * 100);
    i = 0;
    while((temp2 = getchar()) != ' '){
        temp[i] = temp2;
        i++;
    }
    K = atoi(temp);
    ////////
    
    memset(temp, '\0', sizeof(char) * 100);
    i = 0;
    temp2 = '\0';
    while((temp2 = getchar()) != '.'){
        temp[i] = temp2;
        i++;
    }
    G_p = atoi(temp);
    temp2 = '\0';
    memset(temp, '\0', sizeof(char) * 100);
    i = 0;
    while((temp2 = getchar()) != '.'){
        temp[i] = temp2;
        i++;
    }
    S_p = atoi(temp);
    //
    temp2 = '\0';
    memset(temp, '\0', sizeof(char) * 100);
    i = 0;
    while((temp2 = getchar()) != '\n'){
        temp[i] = temp2;
        i++;
    }
    K_p = atoi(temp);
    
    
    int total_p;
    int total_ini;
    int change;
    int K_f,G_f,S_f;
    total_p = 493 * G_p + 29 * S_p + K_p;
    total_ini = 493 * G + 29 * S + K;
    change = total_p - total_ini;
    
    if(change < 0){
        change = -change;
        G_f = change / 493;
        change %= 493;
        S_f = change / 29;
        change %= 29;
        K_f = change;
        cout << '-' << G_f << '.' << S_f << '.' << K_f;
    }
    else{
        G_f = change / 493;
        change %= 493;
        S_f = change / 29;
        change %= 29;
        K_f = change;
        cout << G_f << '.' << S_f << '.' << K_f;
        
    }
    
    return 0;
}

