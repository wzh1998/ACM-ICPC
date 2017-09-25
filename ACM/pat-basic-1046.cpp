//
//  pat-basic-1046.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/21.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int A_shout,A_hua,B_shout,B_hua;
    int A_drink = 0;
    int B_drink = 0;
    
    int i = 0;
    int temp;
    for(i = 0;i < n;i++){
        cin >> A_shout >> A_hua >> B_shout >> B_hua;
        temp = A_shout + B_shout;
        if(A_hua == temp && A_hua != B_hua) B_drink++;
        else if(B_hua == temp && B_hua != A_hua) A_drink++;
        else continue;
    }
    cout << A_drink << ' ' << B_drink;
    
    return 0;
}
