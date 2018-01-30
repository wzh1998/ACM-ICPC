//
//  BJUT_OJ_1040.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/30.
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

int n = 8;
int Column[8];
int f_result[100];
int result = 0;


void search(int row){
    if(row == n) {
        int temp = 0;
        for(int i = 0;i < 8;i++){
            temp *= 10;
            temp += Column[i] + 1;
        }
        f_result[result] = temp;
        result++;
    }
    else{
        for(int i = 0;i < n;i++){
            bool ok = true;
            Column[row] = i;
            for(int j = 0;j < row;j++){
                if(Column[row] == Column[j] || row - Column[row] == j - Column[j] || row + Column[row] == j + Column[j]){
                    ok = false;
                    break;
                }
            }
            if(ok) search(row + 1);
        }
    }
}


int main(void){
    search(0);
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        int temp1;
        cin >> temp1;
        cout << f_result[temp1 - 1] << endl;
    }
    return 0;
}
