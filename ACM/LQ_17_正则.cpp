//
//  LQ_17_正则.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/31.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

char arr[200];
int len;
int pos = 0;

int dfs(){
    int current = 0;
    int res = 0;
    while(pos < len){
        if(arr[pos] == '('){
            pos++;
            current += dfs();
        }
        else if(arr[pos] == ')'){
            pos++;
            break;
        }
        else if(arr[pos] == 'x'){
            pos++;
            current++;
        }
        else if(arr[pos] == '|'){
            res = max(res,current);
            current = 0;
            pos++;
        }
    }
    res = max(res,current);
    
    return res;
}

int main(void){
    scanf("%s",arr);
    len = strlen(arr);
    cout << dfs() << endl;
    
    return 0;
}

