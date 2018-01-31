//
//  BJUT_OJ_1045.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/31.
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

int height;
int length;

int up = 0;
int down = 0;
int left = 0;
int right = 0;

int arr[200][200];
int mark[200][200];
int result = 0;

void dfs(int x,int y,int distance){
    if(x >= 0 && x < height && y >= 0 && y < length){
        
        if(distance > result) result = distance;
        
        if((x - 1) >= 0 && (x - 1) < height && arr[x - 1][y] < arr[x][y]){
            if(mark[x - 1][y] != 0) result = max(result,distance + mark[x - 1][y]);
            else dfs(x - 1,y,distance + 1);
        }
        
        if((x + 1) >= 0 && (x + 1) < height && arr[x + 1][y] < arr[x][y]){
            if(mark[x + 1][y] != 0) result = max(result,distance + mark[x + 1][y]);
            else dfs(x + 1, y, distance + 1);
        }
        
        if((y - 1) >= 0 && (y - 1) < length && arr[x][y - 1] < arr[x][y]){
            if(mark[x][y - 1] != 0) result = max(result,distance + mark[x][y - 1]);
            else dfs(x,y - 1,distance + 1);
        }
        
        if((y + 1) >= 0 && (y + 1) < length && arr[x][y + 1] < arr[x][y]){
            if(mark[x][y + 1] != 0) result = max(result,distance + mark[x][y + 1]);
            else dfs(x,y + 1,distance + 1);
        }
    }
    
}

int main(void){
    memset(mark, 0, sizeof(mark));
    cin >> height >> length;
    
    for(int i = 0;i < height;i++){
        for(int j = 0;j < length;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(int i = 0;i < height;i++){
        for(int j = 0;j < length;j++){
            result = 0;
            dfs(i,j,1);
            mark[i][j] = result;
        }
    }
    
    int maxn = -1;
    for(int i = 0;i < height;i++){
        for(int j = 0;j < length;j++){
            if(mark[i][j] > maxn) maxn = mark[i][j];
        }
    }
    cout << maxn << endl;
    return 0;
}
