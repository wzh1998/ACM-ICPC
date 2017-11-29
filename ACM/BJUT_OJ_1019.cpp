//
//  BJUT_OJ_1019.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/29.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void){
    int T;
    cin >> T;
    int suma,sumb;
    int n;
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        suma = 0;
        sumb = 0;
        for(int j = 0;j < n;j++){
            int temp;
            scanf("%d",&temp);
            if(temp != 100) suma += temp;
            scanf("%d",&temp);
            if(temp != 100) sumb += temp;
        }
        if(suma >= sumb) cout << suma - sumb << endl;
        else cout << "too young too simple" << endl;
    }
}
