//
//  LQ_封印之门.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/28.
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

#define MAXSIZE 26
#define INF 9999999

using namespace std;

int V = 26;
int visit[MAXSIZE];
int dis[MAXSIZE];
int arr[MAXSIZE][MAXSIZE];
int res = 0;
int dij(int s,int e){
    fill(visit,visit + V,false);
    fill(dis,dis + V,INF);
    dis[s] = 0;
    while(1){
        int v = -1;
        for(int i = 0;i < V;i++){
            if(!visit[i] && (v == -1 || dis[i] < dis[v])) v = i;
        }
        if(v == -1) break;
        visit[v] = 1;
        for(int i = 0;i < V;i++){
            dis[i] = min(dis[i], dis[v] + arr[v][i]);
        }
    }
    return dis[e];
    
    
}

int main(void){
    string init,target;
    cin >> init >> target;
    int n;
    cin >> n;
    for(int i = 0;i < V;i++){
        for(int j = 0;j < V;j++) arr[i][j] = INF;
    }
    getchar();
    for(int i = 0;i < n;i++){
        string current;
        getline(cin,current);
        
        int start = current[0] - 'a';
        int end = current[2] - 'a';
        arr[start][end] = 1;
    }
    
    
    
    for(int i = 0;i < init.length();i++){
        int temp = dij((int)(init[i] - 'a'),(int)(target[i] - 'a'));
        if(temp > 26) {
            cout << -1 << endl;
            return 0;
        }
        else res += temp;
    }
    
    cout << res << endl;
    
    return 0;
}
