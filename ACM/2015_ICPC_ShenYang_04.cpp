//
//  2015_ICPC_ShenYang_04.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/7.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a,int b){
    if(a % b == 0) return b;
    return gcd(b,a % b);
}
int main(void){
    int a,b,temp,x,n,num;
    scanf("%d",&x);
    num = 1;
    for(int i = 0;i < x;i++){
        scanf("%d %d %d",&n,&a,&b);
        if(b > a){
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
        temp = gcd(a,b);
        if((n / temp) % 2 == 0){
            //             cout << "Case #" << num << ": Iaka" << endl;
            printf("Case #%d: Iaka\n",num);
        }
        else
            printf("Case #%d: Yuwgna\n",num);
        //            cout << "Case #" << num << ": Yuwgna" << endl;
        num++;
    }
    
    return 0;
}
