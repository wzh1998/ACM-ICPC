//
//  BJUT_OJ_1024.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/22.
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
    for(int i = 0;i < T;i++){
        int a,b;
        cin >> a >> b;
        if(a == b) cout << "Nooooo!!" << endl;
        else{
            if(a > b) cout << "1 " << a - b << endl;
            else if(b > a) cout << "2 " << b - a << endl;
        }
    }
    
    return 0;
}
