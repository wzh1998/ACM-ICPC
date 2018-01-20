//
//  pat-basic-1064.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/20.
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


bool arr[100];

int main(void){
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        int temp;
        int sum = 0;
        cin >> temp;
        while(temp >= 1){
            sum += temp % 10;
            temp /= 10;
        }
        arr[sum] = true;
    }
    int counter = 0;
    for(int i = 0;i < 100;i++){
        if(arr[i]) counter++;;
    }
    cout << counter << endl;
    int temp2 = 0;
    int i;
    for(i = 0;i < 100 && temp2 < counter - 1;i++){
        if(arr[i]){
            temp2++;
            cout << i << " ";
        }
    }
    for(;i < 100;i++){
        if(arr[i]) cout << i;
    }
    
    return 0;
}
