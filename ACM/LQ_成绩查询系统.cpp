//
//  LQ_成绩查询系统.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/15.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

char a[1001][21];
int grade[1001];
int mycounter = 0;

int main(void){
    while(1){
        char temp[5];
        scanf("%s",temp);
        if(strcmp(temp, "end") == 0) break;
        else if(strcmp(temp, "insert") == 0){
            char name[21];
            int gradex;
            scanf("%s",name);
            int i;
            for(i = 0;i < mycounter;i++){
                if(strcmp(a[i], name) == 0) break;
            }
            i != mycounter ? :mycounter++;
            strcpy(a[i], name);
            scanf("%d",&gradex);
            if(gradex > grade[i]) grade[i] = gradex;
        }
        else if(strcmp(temp, "find") == 0){
            char name[21];
            scanf("%s",name);
            int i;
            for(i = 0;i < mycounter;i++){
                if(strcmp(a[i], name) == 0) break;
            }
            if(i == mycounter) cout << -1 << endl;
            else cout << grade[i] << endl;
        }
    }
    
    return 0;
}


