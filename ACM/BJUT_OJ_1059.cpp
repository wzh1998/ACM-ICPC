//
//  BJUT_OJ_1059.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/30.
//  Copyright © 2018年 王子豪. All rights reserved.
//

// not AC yet !!!
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

typedef struct Triangle{
    double b;
    double g;
    double r;
}Triangle;

bool compare(Triangle temp1,Triangle temp2){
    if(temp1.b != temp2.b) return temp1.b < temp2.b;
    else if(temp1.g != temp2.g) return temp1.g < temp2.g;
    else return temp1.r <= temp2.r;
}

int main(void){
    
    int num;
    cin >> num;
    Triangle mtri[num];
    
    for(int i = 0;i < num;i++){
        int PRx,PRy,PGx,PGy,PBx,PBy;
        for(int j = 0;j < 3;j++){
            int temp1,temp2;
            char temp3;
            cin >> temp1 >> temp2 >> temp3;
            if(temp3 == 'R'){
                PRx = temp1;
                PRy = temp2;
            }
            else if(temp3 == 'G'){
                PGx = temp1;
                PGy = temp2;
            }
            else if(temp3 == 'B'){
                PBx = temp1;
                PBy = temp2;
            }
        }
        mtri[i].b = sqrt(pow(PRx - PGx,2) + pow(PRy - PGy,2));
        mtri[i].g = sqrt(pow(PRx - PBx,2) + pow(PRy - PBy,2));
        mtri[i].r = sqrt(pow(PGx - PBx,2) + pow(PGy - PBy,2));
    }
    sort(&mtri[0],&mtri[num],compare);
    int result = 1;
    double pri_b = mtri[0].b;
    double pri_g = mtri[0].g;
    double pri_r = mtri[0].r;
    
    for(int i = 1;i < num;i++){
        if(!(pri_b == mtri[i].b && pri_g == mtri[i].g && pri_r == mtri[i].r)) result++;
        pri_b = mtri[i].b;
        pri_g = mtri[i].g;
        pri_r = mtri[i].r;
    }
    cout << result << endl;
    
    return 0;
}

