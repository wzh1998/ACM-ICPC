//
//  2016_蓝桥校选_D.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/23.
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

typedef struct Point{
    int x;
    int y;
}Point;

char maze[30][30];
int visit[30][30];

int step = 0;
int M = 0,N = 0;
const int INF = -99999;
Point stp,endp;

int bfs(){
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            visit[i][j] = INF;
        }
    }
    queue<Point> myQue;
    myQue.push(stp);
    visit[stp.x][stp.y] = 0;
    
    
    while(myQue.size() != 0){
        Point current = myQue.front();
        int currentx = current.x;
        int currenty = current.y;
        myQue.pop();
        if(currentx == endp.x && currenty == endp.y)break;
        for(int x = -1;x <= 1;x++){
            for(int y = -1;y <= 1;y++){
                if((x == 0 || y == 0) && !(x == 0 && y == 0)){
                    int next_x = currentx + x;
                    int next_y = currenty + y;
                    if(next_x >= 0 && next_x <= M && next_y >= 0 && next_y <= N && visit[next_x][next_y] == INF && maze[next_x][next_y] != '#'){
                        if(maze[next_x][next_y] == '.' || maze[next_x][next_y] == '*'){
                            visit[next_x][next_y] = visit[currentx][currenty] + 1;
                            Point pt ={next_x,next_y};
                            myQue.push(pt);
                        }
                    }
                }
            }
        }
    }
    return visit[endp.x][endp.y];
    
}
int main(void){
    M = -1;
    N = -1;
    while(1){
        memset(maze, '\0', sizeof(maze));
        scanf("%d%d",&M,&N);
        if(M == 0 && N == 0) return 0;
        for(int x = 0;x < M;x++) scanf("%s",maze[x]);
        
        for(int x = 0;x < M;x++){
            for(int y = 0;y < N;y++){
                if(maze[x][y] == '@'){
                    stp.x = x;
                    stp.y = y;
                }
                else if(maze[x][y] == '*'){
                    endp.x = x;
                    endp.y = y;
                }
            }
        }
        int result = bfs();
        result <= 0 ? cout << "-1" << endl : cout << result << endl;
    }
    return 0;
}

