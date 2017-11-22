//
//  2016_蓝桥校选_B.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/22.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef struct elec{
    long long int first;
    long long int second;
    int id;
}elec;
bool compare(elec a,elec b){
    return (a.first >= b.first);
}

int main(void){
    long long int N,K;
    cin >> N >> K;
    elec melec[80000];
    for(int i = 0;i < N;i++){
        scanf("%lld %lld",&melec[i].first,&melec[i].second);
        melec[i].id = i;
    }
    sort(&melec[0],&melec[N],compare);
    long long int maxn = -1;
    long long int resultid = -1;
    for(int i = 0;i < K;i++){
        if(melec[i].second > maxn){
            maxn = melec[i].second;
            resultid = melec[i].id;
        }
    }
    cout << resultid + 1<< endl;
    return 0;
}
