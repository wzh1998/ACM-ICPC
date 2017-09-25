//
//  pat-basic-1023.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/28.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int main(void){
    char temp;
    int temp2;
    char symbol;
    
    char integer;
    char point[13000] = {'\0'};
    int zhishu;
    int z;
    int i = 0;
    cin >> symbol >> integer;
    getchar();
    temp = getchar();
    while(temp != 'E'){
        point[i] = temp;
        i++;
        temp = getchar();
    }
    
    cin >> zhishu;
    
    if(zhishu > 0){
        if(symbol == '-'){
            cout << '-' ;
        }
        cout << integer;
        
        for(z = 0;zhishu > 0;z++,zhishu--){
            if(z >= i) cout << '0' ;
            else cout << point[z];
        }
        if(z < i){
            cout << '.' ;
            for(;z < i;z++){
                if(point[z] == '\0') cout << '0' ;
                else cout << point[z];
            }
        }
    }
    
    else if(zhishu < 0){
        if(symbol == '-'){
            cout << '-' ;
        }
        cout << '0' << '.' ;
        for(;zhishu < -1;zhishu++){
            cout << '0' ;
        }
        cout << integer;
        for(z = 0;z < i;z++){
            cout << point[z];
        }
        
    }
    else if(zhishu == 0){
        if(symbol == '-'){
            cout << '-' ;
        }
        cout << integer ;
        cout << '.' ;
        for(z = 0;z < i;z++){
            cout << point[z];
        }
    }
    return 0;
}
