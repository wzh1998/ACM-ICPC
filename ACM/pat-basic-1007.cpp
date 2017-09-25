//
//  pat-basic-1007.cpp
//  ACM
//
//  Created by 王子豪 on 12/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

bool visit[100002];
int prime[100002];
int n;
int timer = 0;

void getprime()
{
    memset(visit, false, sizeof(visit));
    int num = 0;
    for (int i = 2; i <= n; ++i)
    {
        if ( !visit[i] )  prime[++num] = i;
        for (int j = 1; j <= num && i * prime[j] <= n ;j++)
        {
            visit[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main(void){
    memset(prime,-1,sizeof(prime));
    cin >> n;
    getprime();
    for(int i = 2;prime[i] <= n && i <= 100000 && prime[i] != -1 && prime[i - 1] != -1;i++){
        if((prime[i] - prime[i-1]) == 2) timer++;
    }
    cout << timer;
    return 0;
}
