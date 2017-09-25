//
//  pat-basic-1005.cpp
//  ACM
//
//  Created by 王子豪 on 06/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    int answer;
    int k = 0;
    int temp1[110];
    int temp2;
    int result[10000];
    int final[10000];
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> temp1[i];
        temp2 = temp1[i];
        while(temp2 != 1){
            if(temp2 % 2 == 1){
                temp2 = (temp2 * 3 + 1) / 2;
            }
            else{
                temp2 /= 2;
            }
            
            answer = 0;
            for(int z = 0;z < k;z++){
                if( temp2 == result[z] ) answer = 1;
            }
            if(answer == 0) {
                result[k] = temp2;
                k++;
            }
            
//            for(int i = 0;i < k ;i++){
//                cout << result[i] << ' ';
//            }
//            cout << endl;
        }
    }
    int p = 0;
    for(int a = 0;a < n;a++){
        answer = 0;
        for(int b = 0;b < k;b++){
            if( temp1[a] == result[b] ) answer = 1;
        }
        if(answer == 0) {
            final[p] = temp1[a];
            p++;
        }
    }
    
    sort(&final[0],&final[p]);
    int x = p - 1;
    cout << final[x];
    x--;
    for(;x >= 0;x--) {
        cout << ' ' << final[x];
    }
    
    return 0;
}
