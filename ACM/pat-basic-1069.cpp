//
//  pat-basic-1069.cpp
//  ACM
//
//  Created by 王子豪 on 2017/10/12.
//  Copyright © 2017年 王子豪. All rights reserved.
//

//
//  2015_ICPC_ShenYang_04.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/7.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#include <random>
using namespace std;
int main(void){
    int M,N,S;
    char name[1000][1000];
    char temp[1000];
    
    memset(name,'\0',sizeof(name));
    cin >> M >> N >> S;
    int timer = 0;
    int index = 0;
    for(int i = 0;i < M;i++){
        memset(temp,'\0',sizeof(temp));
        cin >> temp;
        timer++;
        bool result = true;
        if((timer - S) >= 0 && ((timer - S) % N == 0)){
            
            for(int j = 0;j < index;j++){
                if(strcmp(name[j],temp) == 0) {
                    result = false;
                    timer = S - 1;
                    break;
                }
            }
            if(result == true){
                cout << temp << endl;
                strcpy(name[index], temp);
                index++;
            }
        }
    }
    if(strcmp(name[0],"\0") == 0){
        cout << "Keep going..." << endl;
    }
    
    return 0;
}
