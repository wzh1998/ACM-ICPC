//
//  POJ_3040.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/2.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
typedef struct coin{
    int value;
    int num;
}coin;
bool compare(coin a,coin b){
    return (a.value < b.value);
}
int main(void){
    coin mycoin[1000];
    int need[1000];
    int f_ans = 0;
    memset(mycoin, 0, sizeof(mycoin));
    int N,C;
    cin >> N >> C;
    for(int i = 0;i < N;i++){
        scanf("%d %d",&mycoin[i].value,&mycoin[i].num);
        if(mycoin[i].value >= C){
            f_ans += mycoin[i].num;
            mycoin[i].num = 0;
        }
        
    }
    sort(&mycoin[0], &mycoin[N], compare);
    int end = N - 1;
    while(mycoin[end].value >= C) end--;
    
    while(1){
        int co = 0;
        int max = 0;
        bool result = false;
        int current = C;
        memset(need, 0, sizeof(need));
        for(int i = end;i >= 0;i--){
            if(mycoin[i].num != 0){
                co = current / mycoin[i].value;
                max = min(co,mycoin[i].num);
                current -= mycoin[i].value * max;
                need[i] = max;
                if(current == 0){
                    result = true;
                    break;
                }
            }
        }
        if(current > 0){
            for(int i = 0;i < N;i++){
                //                int temp = current / mycoin[i].value;
                //                int trueneed = min(temp, mycoin[i].num);
                //                current -= trueneed * mycoin[i].value;
                //                need[i] += trueneed;
                if(mycoin[i].num > need[i]){
                    while(need[i] < mycoin[i].num){
                        current -= mycoin[i].value;
                        need[i]++;
                        if(current <= 0){
                            result = true;
                            break;
                        }
                    }
                }
                if(result) break;
            }
        }
        if(result == false) break;
        max = 2147483647;
        for(int i = 0;i < N;i++){
            if(need[i]) max = min(max,mycoin[i].num / need[i]);
        }
        f_ans += max;
        for(int i = 0;i < N;i++){
            if(need[i]) mycoin[i].num -= max * need[i];
        }
    }
    cout << f_ans << endl;
    
    
    
    return 0;
}
