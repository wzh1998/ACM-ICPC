//
//  pat-basic-1050.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/23.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
bool compare(int a,int b){
    return a > b;
}
int main(void){
    int x;
    
    int m,n,temp;
    int wide,length;
    int dif = 2147483647;
    int arr[1000001] = { -1 };
    cin >> x;
    m = 1;
    if(x == 1){
        wide = 1;
        length = 1;
    }
    else{
        for(n = 1;n <= x / 2;n++){
            if(x % n == 0){
                m = x / n;
                temp = m - n;
                if(temp < dif && temp >= 0){
                    dif = temp;
                    wide = m;
                    length = n;
                }
            }
        }
    }
    
    
    int i,j;
    for(i = 0;i < x;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr + x,compare);
    
    int **result = (int **) malloc(sizeof(int) * (wide + 10000));
    for(i = 0;i < wide;i++){
        result[i] = (int *)malloc(sizeof(int) * (length + 10000));
    }
    
    int timer = 0;
    int shang,xia,zuo,you;
    shang = 0;
    xia = 0;
    zuo = 0;
    you = 0;
    
    
    
    while(timer < x){
        if(timer >= x) break;
        for(i = zuo,j = shang;i < length - you;i++,timer++){
            result[j][i] = arr[timer];
            if(timer >= x) break;
        }
        shang++;
        i--;
        j++;
        if(timer >= x) break;
        for(;j < wide - xia;j++,timer++){
            result[j][i] = arr[timer];
            if(timer >= x) break;
        }
        you++;
        j--;
        i--;
        if(timer >= x) break;
        for(;i >= zuo;i--,timer++){
            result[j][i] = arr[timer];
            if(timer >= x) break;
        }
        i++;
        j--;
        xia++;
        if(timer >= x) break;
        for(;j >= shang;j--,timer++){
            result[j][i] = arr[timer];
            if(timer >= x) break;
        }
        zuo++;
        j++;
    }
    for(i = 0;i < wide;i++){
        for(j = 0;j < length - 1;j++){
            printf("%d ",result[i][j]);
        }
        printf("%d\n",result[i][j]);
    }
    
    return 0;
}

