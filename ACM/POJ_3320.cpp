//
//  POJ_3320.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/5.
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
#include <set>
#include <map>

using namespace std;


int main(void){
    int T;
    int arr[1000000];
    set<int> question;
    map<int,int> counter;
    
    cin >> T;
    
    for(int i = 0;i < T;i++) scanf("%d",&arr[i]);
    for(int i = 0;i < T;i++) question.insert(arr[i]);
    
    int n = question.size();
    
    int s = 0;
    int t = 0;
    int num = 0;
    int res = T;
    for(;;){
        while(t < T && num < n){
            
            if(counter[arr[t]] == 0) num++;
            
            counter[arr[t]]++;
            t++;
        }
        if(num < n) break;
        res = min(res,t - s);
        
        counter[arr[s]]--;
        if(counter[arr[s]] == 0) num--;
        s++;
    }
    cout << res << endl;
    
    return 0;
}

