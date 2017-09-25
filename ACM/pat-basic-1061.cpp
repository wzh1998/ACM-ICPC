//
//  pat-basic-1061.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/19.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    int n;
    int m;
    int result;
    cin >> n >> m;
    int grade[101] = { 0 };
    int answer[101] = { 0 };
    int i;
    int z;
    int temp;
    for(i = 0;i < m;i++) cin >> grade[i];
    for(i = 0;i < m;i++) cin >> answer[i];
    
    
    for(i = 0;i < n;i++){
        result = 0;
        for(z = 0;z < m;z++){
            cin >> temp;
            if(temp == answer[z]){
                result += grade[z];
            }
        }
        cout << result << endl;
    }
    
    return 0;
}
