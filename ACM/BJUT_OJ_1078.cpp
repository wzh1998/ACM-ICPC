//
//  BJUT_OJ_1078.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/29.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main(void){
    char arr[] = {"qwertyuiopasdfghjkl;zxcvbnm,./"};
    char mark;
    cin >> mark;
    int phase = 0;
    if(mark == 'R') phase = -1;
    else if(mark == 'L') phase = 1;
    string x;
    cin >> x;
    for(int i = 0;i < x.length();i++){
        for(int j = 0;j < strlen(arr);j++){
            if(arr[j] == x[i]){
                cout << arr[j + phase];
                break;
            }
        }
    }
    
    return 0;
}

