//
//  LQ_礼物盒.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/20.
//  Copyright © 2018年 王子豪. All rights reserved.
//

//
//  HW4-2.cpp
//  CHW_2018
//
//  Created by 王子豪 on 2018/3/17.
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
#include <time.h>

using namespace std;

int arr[] = {11,8,11,16,1,2,6,10,17,10,6,5,2,19,4,
    7,5,5,15,3,15,7,11,9,17,9,4,10,12,17,19,20,11,10,20,3};

int visit[100];
int counter = 0;
int res = 0;

void dfs(int current){
    if(current == 100) {
        if(counter > res) {
            res = counter;
            cout << res << " " << clock() << endl;
        }
        return;
    }
    else if(current > 100) return;
    else{
        for(int i = 0;i < 36;i++){
            if(visit[i] == 0){
                visit[i] = 1;
                counter++;
                dfs(current + arr[i]);
                counter--;
                visit[i] = 0;
            }
        }
        return;
    }
}

int main(void){
    
    dfs(0);
    cout << res << endl;
    
    return 0;
}



