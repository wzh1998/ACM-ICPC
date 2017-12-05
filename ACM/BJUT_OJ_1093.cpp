//
//  BJUT_OJ_1093.cpp
//  ACM
//
//  Created by 王子豪 on 2017/12/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    
    //    for(int i = 2;i < 110;i++){
    //        int current = i;
    //        int count = 0;
    //        while(current != 1){
    //            if(current % 2 != 0){
    //                current  = current * 3 + 1;
    //                count ++;
    //            }
    //            else
    //                current = current / 2;
    //        }
    //        cout << count << ",";
    //    }
    
    int T;
    cin >> T;
    int arr[] = {0,0,2,0,1,2,5,0,6,1,4,2,2,5,5,0,3,6,6,1,1,4,4,2,7,2,41,5,5,5,39,0,8,3,3,6,6,6,11,1,40,1,9,4,4,4,38,2,7,7,7,2,2,41,41,5,10,5,10,5,5,39,39,0,8,8,8,3,3,3,37,6,42,6,3,6,6,11,11,1,6,40,40,1,1,9,9,4,9,4,33,4,4,38,38,2,43,7,7,7,7,7,31,2,12,2,36,41,41};
    for(int i = 0;i < T;i++){
        int temp;
        cin >> temp;
        cout << arr[temp - 1] << endl;;
    }
    
    return 0;
    
}
