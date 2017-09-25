//
//  pat-basic-1031.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/14.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void){
    bool result = true;
    int n;
    cin >> n;
    char temp[18];
    char temp2;
    int sum = 0;
    int i;
    char M = '\0';
    for(i = 0;i < n;i++){
        sum = 0;
        getchar();
        scanf("%c",&temp[0]);
        scanf("%c",&temp[1]);
        scanf("%c",&temp[2]);
        scanf("%c",&temp[3]);
        scanf("%c",&temp[4]);
        scanf("%c",&temp[5]);
        scanf("%c",&temp[6]);
        scanf("%c",&temp[7]);
        scanf("%c",&temp[8]);
        scanf("%c",&temp[9]);
        scanf("%c",&temp[10]);
        scanf("%c",&temp[11]);
        scanf("%c",&temp[12]);
        scanf("%c",&temp[13]);
        scanf("%c",&temp[14]);
        scanf("%c",&temp[15]);
        scanf("%c",&temp[16]);
        temp[17] = '\0';
        sum += (temp[0] - 48) * 7;
        sum += (temp[1] - 48) * 9;
        sum += (temp[2] - 48) * 10;
        sum += (temp[3] - 48) * 5;
        sum += (temp[4] - 48) * 8;
        sum += (temp[5] - 48) * 4;
        sum += (temp[6] - 48) * 2;
        sum += (temp[7] - 48) * 1;
        sum += (temp[8] - 48) * 6;
        sum += (temp[9] - 48) * 3;
        sum += (temp[10] - 48) * 7;
        sum += (temp[11] - 48) * 9;
        sum += (temp[12] - 48) * 10;
        sum += (temp[13] - 48) * 5;
        sum += (temp[14] - 48) * 8;
        sum += (temp[15] - 48) * 4;
        sum += (temp[16] - 48) * 2;
        
        
        sum %= 11;
        if(sum == 0){
            M = '1';
        }
        else if(sum == 1){
            M = '0';
        }
        else if(sum == 2){
            M = 'X';
        }
        else if(sum == 3){
            M = '9';
        }
        else if(sum == 4){
            M = '8';
        }
        else if(sum == 5){
            M = '7';
        }
        else if(sum == 6){
            M = '6';
        }
        else if(sum == 7){
            M = '5';
        }
        else if(sum == 8){
            M = '4';
        }
        else if(sum == 9){
            M = '3';
        }
        else if(sum == 10){
            M = '2';
        }
        scanf("%c",&temp2);
        if(temp2 != M) {
            result = false;
            printf("%s%c\n",temp,temp2);
        }
        
    }
    
    if(result == true) cout << "All passed";
    return 0;
}
