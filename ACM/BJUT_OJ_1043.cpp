//
//  BJUT_OJ_1043.cpp
//  ACM
//
//  Created by 王子豪 on 2017/12/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    char arr[100][100];
    int a,b;
    cin >> a >> b;
    for(int i = 0;i < a;i++) scanf("%s",arr[i]);
    for(int i = 0;i < a;i++){
        for(int j = 0;j < b;j++){
            if(arr[i][j] == '*') cout << "*";
            else if(arr[i][j] == '?'){
                int count = 0;
                for(int x = -1;x <= 1;x++){
                    for(int y = -1;y <= 1;y++){
                        int nextx = i + x;
                        int nexty = j + y;
                        if(nextx >= 0 && nextx < a && nexty >= 0 && nexty < b){
                            if(arr[nextx][nexty] == '*') count++;
                        }
                        else continue;
                    }
                }
                cout << count;
            }
        }
        cout << endl;
    }
    return 0;
}

