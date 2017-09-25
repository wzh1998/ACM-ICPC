//
//  ccpc-1004.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/19.
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
    
    char s1[1000003] = { '\0' } ;
    char s2[1000003] = { '\0' };
    int length1;
    int length2;
    bool answer = true;
    int T;
    cin >> T;
    int t;
    int i;
    int j;
    int k;
    int x;
    int Ni;
    int result;
    int length_s1;
    int length_s2;
    char s2_result[1000003] = { '\0' };
    for(i = 0;i < T;i++){
        result = 0;
        scanf("%s",s1);
        scanf("%s",s2);
        for(length_s1 = 0;s1[length_s1] != '\0';length_s1++);
        for(length_s2 = 0;s2[length_s2] != '\0';length_s2++);
        for(j = 0;j < length_s2;j++){
            for(k = j;k < length_s2;k++){
                s2_result[k - j] = s2[k];
            }
            
            Ni = 0;
            length1 = length_s1;
            length2 = length_s2 - j;
            t = length2;
            int temp2;
            for(x = 0;x <= length1 - length2;x++){
                temp2 = x;
                t = length2;
                answer = true;
                while(t > 0){
                    if(s1[temp2] == s2_result[length2 - t]){
                        temp2++;
                        t--;
                    }
                    else {
                        answer = false;
                        break;
                    }
                }
                if(answer == true)Ni++;
                
            }
            result += Ni * length2 ;
            result %= 1000000007;
        }
        cout << result << endl;
    }
    return 0;
}
