//
//  pat-basic-1038.cpp
//  ACM
//
//  Created by 王子豪 on 2017/8/17.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;
int main(void){
    int n;
    cin >> n;
    int temp;
    int array[101] = {0};
    int i;
    for(i = 0;i < n;i++){
        cin >> temp;
        array[temp]++;
    }
    int k;
    cin >> k;
    for(i = 0;i < k - 1;i++){
        cin >> temp;
        cout << array[temp] << ' ';
    }
    cin >> temp;
    cout << array[temp];
    
    return 0;
}
