//
//  pat-top-1002.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/15.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int table[100][10000];
int maxn = 0;
int total = 0;
int n;

struct bag{
    int profit;
    int cost;
    int deadline;
}xbag[1000];

bool compare(bag a,bag b){
    if(a.deadline == b.deadline) return a.cost < b.cost;
    else return a.deadline < b.deadline;
}

int main(void){
    table[0][0] = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> xbag[i].profit;
        cin >> xbag[i].cost;
        cin >> xbag[i].deadline;
        table[i][0] = 0;
        total += xbag[i].cost;
    }
    
    sort(&xbag[0] ,&xbag[n + 1] ,compare);
    
    for(int i = 1;i <= n;i++){
        for(int k = 1;k <= total;k++){
            if(k <= xbag[i].deadline){
                table[i][k] = max(table[i - 1][k - xbag[i].cost] + xbag[i].profit,table[i - 1][k]);
            }
            else{
                table[i][k] = xbag[i].profit;
            }
            if(table[i][k] > maxn)
                maxn = table[i][k];
        }
    }
    cout << maxn;
}
