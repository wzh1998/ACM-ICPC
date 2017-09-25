//
//  pat-advance-1003.cpp
//  ACM
//
//  Created by 王子豪 on 08/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>

using namespace std;

int city[501];
int road[501][501] = {0};
int min_length[501] = {0};
int sum_team[501] = {0};
int same_city[501] = {0};
bool visit[501] = {false};

void dijkstra(int setout,int target,int n){
    int i;
    int t;
    int minimum;
    int next;
    int count = 0;
    int current;
    
    current = setout;
    sum_team[current] = city[current];
    same_city[current] = 1;
    
    for(;count < n - 1;count++){
        minimum = 2147483647;
        visit[current] = true;
        for(i = 0;i < n;i++){
            if(visit[i] == true)
                continue;
            if(road[current][i]){
                t = min_length[current] + road[current][i];
                if(t == min_length[i]){
                    same_city[i] = same_city[i] + same_city[current];
                    if(sum_team[current] + city[i] > sum_team[i])
                        sum_team[i] = sum_team[current] + city[i];
                }
                else if(t < min_length[i] || min_length[i] == 0){
                    same_city[i] = same_city[current];
                    sum_team[i] = sum_team[current] + city[i];
                    min_length[i] = t;
                }
            }
            if(min_length[i] != 0 && min_length[i] < minimum ){
                minimum = min_length[i];
                next = i;
            }
        }
        min_length[current] = minimum;
        if(next == target) break;
        current = next;
    }
}



int main(void){
    int N;
    int M;
    int setout;
    int target;
    int i;
    
    cin >> N >> M >> setout >> target;
    for(i = 0;i < N;i++) cin >> city[i];
    int c1,c2;
    for(i = 0;i < M;i++){
        cin >> c1 >> c2;
        cin >> road[c1][c2];
        road[c2][c1] = road[c1][c2];
    }
    if(setout == target){
        cout << 1 << ' ' << city[setout] << endl;
        return 0;
    }
    dijkstra(setout, target, N);
    cout << same_city[target] << ' ' << sum_team[target] << endl;
    return 0;
}















