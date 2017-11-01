//
//  POJ_2376.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef struct caw{
    int start;
    int end;
}caw;

bool compare(caw a,caw b){
    if(a.end != b.end) return (a.start < b.start);
    else return (a.end < b.end);
}

int main(void){
    int N,T;
    caw mycaw[100000];
    memset(mycaw, 0, sizeof(mycaw));
    cin >> N >> T;
    for(int i = 0;i < N;i++) scanf("%d %d",&mycaw[i].start,&mycaw[i].end);
    int start = 0;
    int end = 0;
    int result = 0;
    int i = 0;
    bool temp = true;
    sort(&mycaw[0], &mycaw[N], compare);
    while(end < T){
        start = end + 1;
        for(int j = i;j < N;j++){
            if(mycaw[j].start <= start){
                if(mycaw[j].end >= start){
                    end = max(end, mycaw[j].end);
                }
            }
            else{
                i = j;
                break;
            }
        }
        if(end < start){
            temp = false;
            break;
        }
        else result++;
    }
    
    if(temp == false || end < T) cout << "-1" << endl;
    else cout << result << endl;
    
    return 0;
}
