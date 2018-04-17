//
//  2017秋集训_2002.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/1.
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
    return (a.end < b.end);
}
int main(void){
    Course myCourse[100000];
    memset(myCourse, -1, sizeof(myCourse));
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> myCourse[i].start;
        cin >> myCourse[i].end;
    }

    sort(&myCourse[0], &myCourse[n], compare);
    int result = 0;
    int c_start = 0;
    int c_end = 0;
    for(int z = 0;z < n;z++){
        if(myCourse[z].start > c_end){
            c_start = myCourse[z].start;
            c_end = myCourse[z].end;
            result++;
        }
    }
    cout << result << endl;
    
    return 0;
}
