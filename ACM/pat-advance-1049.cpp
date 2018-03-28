//
//  pat-advance-1049.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/27.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;
typedef long long ll;
ll mcount(ll current){
    ll temp = current;
    ll base = 1;
    
    ll result = 0;
    while(temp > 0){
        ll weight = temp % 10;
        ll round = temp / 10;
        result += round * base;
        if(weight == 1) result += (current % base) + 1;
        else if(weight > 1) result += base;
        base *= 10;
        temp /= 10;
    }
    cout << result << endl;
    return result;
}
int main(void){
    int n;
    cin >> n;
    mcount(n);
    
    return 0;
}

