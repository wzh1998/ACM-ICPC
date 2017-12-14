//
//  BJUT_OJ_1090.cpp
//  ACM
//
//  Created by 王子豪 on 2017/12/8.
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

const int MAX_N = 1000000;
int data[3000100];
int arr[1000100];
int n;

void init(int n_){
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0;i < n * 2 - 1;i++) data[i] = 2147483647;
}

void update(int k,int a){ // k是index
    k += n - 1;
    data[k] = a;
    while(k > 0){
        k = (k - 1) / 2;
        data[k] = min(data[2 * k + 1],data[2 * k + 2]);
    }
}
int query(int a,int b,int k,int left,int right){
    if(right < a || left > b) return 2147483647;
    if(a <= left && b >= right) return data[k];
    else{
        int valeft = query(a, b, k * 2 + 1, left, (left + right) / 2);
        int varight = query(a, b, k * 2 + 2, (left + right) / 2 + 1 , right);
        return min(valeft,varight);
    }
}


void init2(int n_){
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0;i < n * 2 - 1;i++) data[i] = -2147483648;
}

void update2(int k,int a){ // k是index
    k += n - 1;
    data[k] = a;
    while(k > 0){
        k = (k - 1) / 2;
        data[k] = max(data[2 * k + 1],data[2 * k + 2]);
    }
}
int query2(int a,int b,int k,int left,int right){
    if(right < a || left > b) return -2147483648;
    if(a <= left && b >= right) return data[k];
    else{
        int valeft = query2(a, b, k * 2 + 1, left, (left + right) / 2);
        int varight = query2(a, b, k * 2 + 2, (left + right) / 2 + 1 , right);
        return max(valeft,varight);
    }
}

int main(void){
    int num,window;
    cin >> num >> window;
    init(num);
    
    
    for(int i = 0;i < num;i++){
        scanf("%d",&arr[i]);
        update(i, arr[i]);
    }
    int start = 0;
    int end = window - 1;
    for(;end < num;end++,start++)
        cout << query(start + n - 1, end + n - 1, 0,n - 1,2 * n - 2) << " ";
    
    cout << endl;
    /////////////////////
    init2(num);
    for(int i = 0;i < num;i++) update2(i, arr[i]);
    start = 0;
    end = window - 1;
    for(;end < num;end++,start++)
        cout << query2(start + n - 1, end + n - 1, 0,n - 1,2 * n - 2) << " ";
    return 0;
}
