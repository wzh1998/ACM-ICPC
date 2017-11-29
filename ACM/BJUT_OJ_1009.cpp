//
//  BJUT_OJ_1009.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/29.
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

char maze[100][100];
int visit[100][100];

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
                        if(maze[next_x][next_y] == '.'){
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
    memset(maze, '\0', sizeof(maze));
    
    cin >> M >> N;
    for(int x = 0;x < M;x++) scanf("%s",maze[x]);
    
    stp.x = 0;
    stp.y = 0;
    endp.x = M - 1;
    endp.y = N - 1;
    
    int result = bfs();
    cout << result + 1 << endl;
    
    return 0;
}
