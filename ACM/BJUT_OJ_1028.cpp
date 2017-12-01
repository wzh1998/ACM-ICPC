//
//  BJUT_OJ_1028.cpp
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
    
    bool result = true;
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        result = true;
        string x;
        cin >> x;
        int len = x.length();
        for(int j = 0;j < (len / 2);j++){
            if(x[j] != x[len - 1 - j]) result = false;
        }
        (result == true) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    
    
    
    return 0;
}
