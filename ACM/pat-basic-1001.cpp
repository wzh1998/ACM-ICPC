//
//  pat-basic-1001.cpp
//  ACM
//
//  Created by 王子豪 on 04/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void){
    int num;
    cin >> num;
    int timer = 0;
    while( num != 1){
        if( num % 2 == 0 ) num /= 2;
        else num = (num * 3 + 1) / 2;
        timer++;
    }
    cout << timer;
    return 0;
}
