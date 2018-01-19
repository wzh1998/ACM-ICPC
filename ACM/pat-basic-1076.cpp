//
//  pat-basic-1076.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/19.
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
    char arr[1000][1000];
    cin >> T;
    for(int i = 0;i < 4 * T;i++){
        cin >> arr[i];
    }
    for(int i = 0;i < 4 * T;i++){
        if(arr[i][2] == 'T'){
            if(arr[i][0] == 'A') cout << 1;
            else if(arr[i][0] == 'B') cout << 2;
            else if(arr[i][0] == 'C') cout << 3;
            else if(arr[i][0] == 'D') cout << 4;
        }
    }
    
    return 0;
}
