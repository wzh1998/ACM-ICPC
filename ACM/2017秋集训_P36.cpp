//
//  2017秋集训_P36.cpp
//  ACM
//
//  Created by 王子豪 on 2017/10/24.
//  Copyright © 2017年 王子豪. All rights reserved.
//



#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;
const int INF = 9999999;

char arr[150][150];
int visit[150][150];
int N,M;
int start_x;
int start_y;
int end_x;
int end_y;
int result = 0;
typedef struct Point{
    int x;
    int y;
}Point;

int bfs(){
    queue<Point> myQue;
    Point sta_P = {start_x,start_y};
    Point fin_P = {end_x,end_y};
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            visit[i][j] = INF;
        }
    }
    myQue.push(sta_P);
    visit[start_x][start_y] = 0;
    while(myQue.size() != 0){
        Point current = myQue.front();
        myQue.pop();
        if(current.x == fin_P.x && current.y == fin_P.y) break;
        for(int xx = -1;xx <= 1;xx++){
            for(int yy = -1;yy <= 1;yy++){
                if((xx == 0 || yy == 0)&& !(xx == 0 && yy == 0)){
                    int n_x = current.x + xx;
                    int n_y = current.y + yy;
                    if(n_x >= 0 && n_x < N && n_y >= 0 && n_y < M && visit[n_x][n_y] == INF && arr[n_x][n_y] != '#'){
                        Point newin = {n_x,n_y};
                        myQue.push(newin);
                        visit[n_x][n_y] = visit[current.x][current.y] + 1;
                        //                        result++;
                    }
                }
            }
        }
        //        result++;
    }
    return visit[fin_P.x][fin_P.y];
}
int main(void){
    cin >> N >> M;
    getchar();
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            scanf("%c",&arr[i][j]);
            if(arr[i][j] == 'S'){
                start_x = i;
                start_y = j;
            }
            else if(arr[i][j] == 'G'){
                end_x = i;
                end_y = j;
            }
        }
        getchar();
    }
    
    result = bfs();
    
    cout << result;
    
}
