//
//  POJ_3617.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    char ori[10000];
    int len = 0;
    cin >> len;
    for(int i = 0;i < len;i++) scanf("%s",&ori[i]);
    //    memset(ori, '\0', sizeof(ori));
    //    memset(rev,'\0',sizeof(rev));
    
    int left = 0;
    int right = len-1;
    bool result;
    int counter = 0;
    while(left <= right){
        result = false;
        for(int i = 0;left + i <= right;i++){
            if(ori[left+i] < ori[right-i]){
                result = true;
                break;
            }
            else if(ori[left+i] > ori[right-i]) {
                result = false;
                break;
            }
        }
        if(result){
            if(counter == 80){
                counter = 0;
                cout << endl;
            }
            cout << ori[left];
            counter++;
            left++;
        }
        else{
            if(counter == 80){
                counter = 0;
                cout << endl;
            }
            cout << ori[right];
            counter++;
            right--;
        }
    }
    //    printf("\n");
    return 0;
}
