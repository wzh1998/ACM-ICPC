//
//  BJUT_OJ_1058.cpp
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
    int T;
    cin >> T;
    int a,b;
    for(int i = 0;i < T;i++){
        cin >> a >> b;
        if(a % 2 == 0 && b % 2 == 0) cout << "KUSO GAME!" << endl;
        else if(a % 2 == 0 && b % 2 == 1) cout << "2" << endl;
        else if(a % 2 == 1 && b % 2 == 0) cout << "1" << endl;
        else if(a % 2 == 1 && b % 2 == 1) cout << "3" << endl;
    }
    
    return 0;
}

