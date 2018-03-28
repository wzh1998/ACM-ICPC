//
//  JSK_得克萨斯长角牛.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/21.
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
#include <set>
#include <cmath>
#define MAXN 3000

using namespace std;


int cost[MAXN][MAXN];
int dis[MAXN];
bool visited[MAXN];
int T,C,Ts,Te;

void dij(int s){
    fill(dis, dis + T + 1, 99999);
    fill(visited,visited + T + 1,false);
    dis[s] = 0;
    while(1){
        int v = -1;
        for(int u = 0;u < T;u++){
            if(!visited[u] && (v == -1 || dis[u] < dis[v])) v = u;
        }
        if(v == -1) break;
        visited[v] = true;
        for(int u = 0;u < T;u++){
            dis[u] = min(dis[u], dis[v] + cost[v][u]);
        }
    }
    
}

int main(void){
    cin >> T >> C >> Ts >> Te;
    for(int i = 0;i < T;i++){
        for(int j = 0;j < T;j++){
            cost[i][j] = 99999;
        }
    }
    for(int i = 0;i < C;i++){
        
        int x,y,temp;
        cin >> x >> y >> temp;
        if(cost[x - 1][y - 1] != 0) {
            if(temp < cost[x - 1][y - 1]){
                cost[x - 1][y - 1] = temp;
                cost[y - 1][x - 1] = temp;
            }
        }
        else {
            cost[x - 1][y - 1] = temp;
            cost[y - 1][x - 1] = temp;
        }
    }
    dij(Ts - 1);
    cout << dis[Te - 1] << endl;
    
    return 0;
}
