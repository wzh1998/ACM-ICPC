//
//  BJUT_OJ_1044.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/22.
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
#include <cmath>

using namespace std;
int main(void){
    char current[200];
    stack<int> mystack;
    int result[101];
    memset(current,'\0',sizeof(current));
    memset(result, 0, sizeof(result));
    
    while(~scanf("%s",current)){
        for(int i = 0;i < strlen(current);i++){
            if(current[i] == '(') {
                mystack.push(i);
                result[i] = 3;
            }
            else if(current[i] == ')'){
                if(mystack.empty()) result[i] = 1;
                else {
                    mystack.pop();
                    result[i] = 3;
                }
            }
            else if((current[i] >= 'A' && current[i] <= 'Z') || (current[i] >= 'a' && current[i] <= 'z')) result[i] = 3;
        }
        while(!mystack.empty()){
            int temp = mystack.top();
            result[temp] = -1;
            mystack.pop();
        }
        cout << current << endl;
        for(int i = 0;i < 101;i++){
            if(result[i] == -1) cout << '$';
            else if(result[i] == 1) cout << '?';
            else if(result[i] == 3) cout << ' ';
        }
        cout << endl;
        memset(current,'\0',sizeof(current));
        memset(result, 0, sizeof(result));
    }
    return 0;
}
