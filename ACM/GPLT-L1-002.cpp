//
//  GPLT-L1-002.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/17.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>


using namespace std;

int main(void){
    
    int T;
    char x;
    int current = 3;
    
    int sum = 1;
    cin >> T;
    cin >> x;
    if(T == 0){
        cout << "0" << endl;
        return 0;
    }
    else if(T < 7) {
        cout << x << endl;
        cout << T - 1 << endl;
        return 0;
    }
    while(true){
        if((sum + current) > T) break;
        else{
            sum = sum + current * 2;
            current += 2;
        }
    }
    current -= 2;
    int timer = 0;
    for(int i = current;i >= 1;i -= 2){
        for(int j = 0;j < timer;j++) cout << " ";
        for(int j = 0;j < i;j++){
            cout << x;
        }
        cout << endl;
        timer++;
    }
    timer -= 2;
    for(int i = 3;i <= current;i += 2){
        for(int j = 0;j < timer;j++) cout << " ";
        for(int j = 0;j < i;j++){
            cout << x;
        }
        cout << endl;
        timer--;
    }
    
    cout << T - sum << endl;
    return 0;
}
