//
//  BJUT_OJ_1016.cpp
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
    int high;
    int length;
    char sym;
    int para;
    cin >> high >> length >> sym >> para;
    char a = sym;
    char b = ' ';
    if(para == 1) b = sym;
    
    for(int i = 0;i < length;i++){
        cout << a;
    }
    cout << endl;
    
    for(int j = 1;j < high - 1;j++){
        cout << a;
        for(int i = 1;i < length - 1;i++) cout << b;
        cout << a << endl;
    }
    
    for(int i = 0;i < length;i++){
        cout << a;
    }
    cout << endl;
    
    return 0;
}

