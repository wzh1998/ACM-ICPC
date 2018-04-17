//
//  BJUT_OJ_181B.cpp
//  ACM
//
//  Created by 王子豪 on 2018/4/17.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#define MAXSIZE 10000

using namespace std;

bool visit[MAXSIZE];
long long n,w;

typedef struct Course{
    long long start;
    long long end;
}Course;

bool compare(Course a,Course b){
    return (a.end < b.end);
}


int main(void){
    Course myCourse[MAXSIZE];
    
    memset(myCourse, -1, sizeof(myCourse));
    memset(visit, false, sizeof(visit));
    
    scanf("%lld%lld",&n,&w);
    for(long long i = 0;i < n;i++){
        scanf("%lld",&myCourse[i].start);
        scanf("%lld",&myCourse[i].end);
    }
    
    sort(&myCourse[0], &myCourse[n], compare);
    long long result = 0;
    for(long long p = 0;p < w;p++){
        long long c_start = 0;
        long long c_end = 0;
        for(long long z = 0;z < n;z++){
            if(!visit[z]){
                if(myCourse[z].start > c_end){
                    c_start = myCourse[z].start;
                    c_end = myCourse[z].end;
                    visit[z] = true;
                    result++;
                    if(result == n) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
            
        }
    }
    cout << "No" << endl;
    
    return 0;
}
