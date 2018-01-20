//
//  BJUT_OJ_1002.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/20.
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
    int T;
    scanf("%d",&T);
    getchar();
    for(int i = 0;i < T;i++){
        string current;
        getline(cin,current);
        if(current.length() == 0) {
            cout << "Case " << i + 1 << ": " << 0 << endl;
            continue;
        }
        stack <long long int> mystack;
        for(int j = 0;j < current.length();j++){
            if(current[j] >= '0' && current[j] <= '9'){
                int f_num = current[j++] - '0';
                while(current[j] != ' '){
                    f_num *= 10;
                    f_num += current[j++] - '0';
                }
                mystack.push(f_num);
                continue;
            }
            else if(current[j] == '+'){
                long long int temp1 = mystack.top();
                mystack.pop();
                long long int temp2 = mystack.top();
                mystack.pop();
                mystack.push(temp1 + temp2);
            }
            else if(current[j] == '*'){
                long long int temp1 = mystack.top();
                mystack.pop();
                long long int temp2 = mystack.top();
                mystack.pop();
                mystack.push(temp1 * temp2);
            }
        }
        long long int ans = mystack.top();
        cout << "Case " << i + 1 << ": " << ans << endl;;
        mystack.pop();
    }
    return 0;
}
