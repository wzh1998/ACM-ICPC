//
//  POJ_3069.cpp
//  ACM
//
//  Created by 王子豪 on 2017/10/28.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

int main(void){
    int R,N;
    cin >> R >> N;
    while(!(R == -1 && N == -1)){
        int arr[10000];
        for(int i = 0;i < N;i++){
            cin >> arr[i];
        }
        sort(&arr[0], &arr[N]);
        int temp;
        int mid;
        int result = 0;
        if(R == 0){
            int x = arr[0];
            result++;
            for(int i = 1;i < N;i++){
                if(arr[i] != x) result++;
                x = arr[i];
            }
        }
        else{
            for(int j = 0;j < N;){
                temp = arr[j] + R;
                mid = j;
                while(arr[mid] <= temp && mid < N) mid++;
                mid--;
                temp = arr[mid] + R;
                result++;
                while(arr[mid] <= temp && mid < N) mid++;
                j = mid;
            }
        }
        cout << result << endl;
        cin >> R >> N;
    }
    return 0;
}
