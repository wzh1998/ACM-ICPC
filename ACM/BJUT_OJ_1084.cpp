//
//  BJUT_OJ_1084.cpp
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
    
    double result[500];
    result[0] = -1;
    result[1] = -1;
    result[2] = -1;
    for(int i = 3;i < 500;i++){
        double temp = i;
        result[i] = (temp - 2) * 180 / temp;
    }
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        double num;
        cin >> num;
        int pos = lower_bound(&result[0], &result[499], num) - result;
        if(result[pos] == num) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
