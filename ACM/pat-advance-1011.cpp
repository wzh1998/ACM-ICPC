//
//  pat-basic-1023.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/28.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

double max1(double a,double b,double c){
    double max = -1;
    if(a > max) max = a;
    if(b > max) max = b;
    if(c > max) max = c;
    return max;
}

int main(void){
    double w1,w2,w3;
    double t1,t2,t3;
    double l1,l2,l3;
    
    
    char result1,result2,result3;
    result1 = 'x';
    result2 = 'x';
    result3 = 'x';
    
    double f_result;
    
    cin >> w1 >> t1 >> l1;
    cin >> w2 >> t2 >> l2;
    cin >> w3 >> t3 >> l3;
    double ma,mb,mc;
    if(w1 == max1(w1,t1,l1)) result1 = 'W';
    else if(t1 == max1(w1,t1,l1)) result1 = 'T';
    else if(l1 == max1(w1,t1,l1)) result1 = 'L';
    
    if(w2 == max1(w2,t2,l2)) result2 = 'W';
    else if(t2 == max1(w2,t2,l2)) result2 = 'T';
    else if(l2 == max1(w2,t2,l2)) result2 = 'L';
    
    if(w3 == max1(w3,t3,l3)) result3 = 'W';
    else if(t3 == max1(w3,t3,l3)) result3 = 'T';
    else if(l3 == max1(w3,t3,l3)) result3 = 'L';
    ma = max1(w1,t1,l1);
    mb = max1(w2,t2,l2);
    mc = max1(w3,t3,l3);
    cout << result1 << ' ' << result2 << ' ' << result3;
    f_result = (ma * mb * mc * 0.650000 - 1) * 2;
    printf(" %.2lf",f_result);
    
    return 0;
}
