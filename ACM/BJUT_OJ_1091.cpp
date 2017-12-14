//
//  BJUT_OJ_1091.cpp
//  ACM
//
//  Created by 王子豪 on 2017/12/4.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a,int b){
    return (b == 0) ? a : gcd(b, a % b);
}

int arr[100000];

int main(void){
    int a,b,n;
    cin >> a >> b;
    
    cin >> n;
    int result;
    a > b? result = gcd(a,b) : result = gcd(b,a);
    int k = 0;
    for(int i = 1;i <= sqrt(result);i++){
        if(result % i == 0){
            arr[k] = i;
            k++;
            arr[k] = result / i;
            k++;
        }
    }
    arr[k] = result;
    k++;
    for(int x = 0;x < n;x++){
        int lower,higher;
        cin >> lower >> higher;
        int i;
        int finalx = -1;
        for(i = 0;i < k;i++){
            if(arr[i] >= lower && arr[i] <= higher){
                if(arr[i] > finalx) finalx = arr[i];
            }
        }
        cout << finalx << endl;
    }
    return 0;
}

