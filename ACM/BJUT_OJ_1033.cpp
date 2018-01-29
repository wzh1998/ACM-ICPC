//
//  BJUT_OJ_1033.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/29.
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
typedef struct range{
    int low;
    int high;
}range;

bool compare(range a,range b){
    if(a.low != b.low) return a.low < b.low;
    else return a.high <= b.high;
}
int main(void){
    int T;
    range myrange[50001];
    memset(myrange, 0, sizeof(myrange));
    cin >> T;
    for(int i = 0;i < T;i++) scanf("%d %d",&myrange[i].low,&myrange[i].high);
    sort(&myrange[0],&myrange[T],compare);
    int current;
    int maxn = myrange[0].high;
    for(int i = 1;i < T;i++){
        current = myrange[i].low;
        if(current > maxn) {
            cout << "no" << endl;
            return 0;
        }
        if(myrange[i].high > maxn) maxn = myrange[i].high;
        
    }
    cout << myrange[0].low << " " << maxn << endl;
    
    return 0;
}

