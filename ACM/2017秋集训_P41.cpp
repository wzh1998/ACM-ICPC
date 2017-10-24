//
//  2017秋集训_P41.cpp
//  ACM
//
//  Created by 王子豪 on 2017/10/24.
//  Copyright © 2017年 王子豪. All rights reserved.
//



#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

typedef struct Course{
    int start;
    int end;
}Course;
bool compare(Course a,Course b){
    if(a.end != b.end) return (a.end < b.end);
    else return (a.start < b.start);
}
int main(void){
    Course myCourse[100];
    memset(myCourse, -1, sizeof(myCourse));
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> myCourse[i].start;
    }
    for(int j = 0;j < n;j++){
        cin >> myCourse[j].end;
    }
    sort(&myCourse[0], &myCourse[n], compare);
    int result = 0;
    int c_start = 0;
    int c_end = 0;
    for(int z = 0;z < n;z++){
        if(myCourse[z].start >= c_end){
            c_start = myCourse[z].start;
            c_end = myCourse[z].end;
            result++;
        }
    }
    cout << result;
    
    return 0;
}
