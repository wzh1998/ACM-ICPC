//
//  shu-p32.cpp
//  ACM
//
//  Created by 王子豪 on 2017/10/21.
//  Copyright © 2017年 王子豪. All rights reserved.
//



#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

int N,M;
char arr[100][100];

void dfs(int current_x,int current_y){
    arr[current_x][current_y] = '.';
    for(int x = -1;x <= 1;x++){
        for(int y = -1;y <= 1;y++){
            //                if(!(x==0 && y ==0)){
            if(arr[current_x + x][current_y+y] == 'W' && (current_x + x) >= 0 && (current_y+y) >=0 && (current_y + y) < M && (current_x + x) < N ){
                dfs(current_x + x, current_y + y);
            }
            //                }
        }
    }
}

int main(void){
    scanf("%d %d",&N,&M);
    //    getchar();
    int result = 0;
    //    memset(arr, '\0', sizeof(arr));
    for(int i = 0;i < N;i++){
        getchar();
        for(int j = 0;j < M;j++){
            scanf("%c",&arr[i][j]);
        }
        
    }
    
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(arr[i][j] == 'W'){
                dfs(i, j);
                result++;
            }
        }
    }
    cout << result;
    return 0;
}
