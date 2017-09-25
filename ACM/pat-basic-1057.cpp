//
//  pat-basic-1057.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/30.
//  Copyright © 2017年 王子豪. All rights reserved.
//

//
//  Bash Game.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/29.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

char a[100100];
int temp[100100];

int main(void){
    memset(temp,-1,sizeof(int) * 100100);
    memset(a,'\0',sizeof(char) * 100100);
    char x = '\0';
    int i = 0;
    while((x = getchar()) != '\n'){
        a[i] = x;
        i++;
    }
    for(i = 0;a[i] != '\0';i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            a[i] += 'a' - 'A';
        }
        if(a[i] >= 'a' && a[i] <= 'z'){
            temp[i] = a[i] - 'a' + 1;
        }
    }
    int sum = 0;
    int remain;
    int count0 = 0;
    int count1 = 0;
    for(i = 0;i < 100100;i++){
        if(temp[i] != -1){
            sum += temp[i];
        }
    }
    while(sum > 0){
        remain = sum % 2;
        if(remain == 0) count0++;
        else count1++;
        sum /= 2;
    }
    cout << count0 << ' ' << count1;
    
    return 0;
}
