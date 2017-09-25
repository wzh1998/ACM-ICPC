//
//  pat-basic-1013.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/22.
//  Copyright © 2017年 王子豪. All rights reserved.
//
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

bool visit[5000000];
int prime[5000000];
int n = 5000000;

int M,N;
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
    getprime();
    cin >> M >> N;
    int i = M;
    int timer = 1;
    
    for(; i < N ;i++){
        if(timer == 10 ){
            cout << prime[i] << endl;
            timer = 1;
        }
        else{
            cout << prime[i] << ' ';
            timer++;
        }
    }
    cout << prime[i];
    
    return 0;
}
