//
//  pat-basic-1006.cpp
//  ACM
//
//  Created by 王子豪 on 04/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void){
    string n;
    cin >> n;
    int t,a;
    t = n.length();
    int temp;
    if( t == 3 ){
        temp = (int)n[0] - 48;
        while( temp != 0 ){
            cout << 'B';
            temp--;
        }
        temp = (int)n[1] - 48;
        while(temp != 0){
            cout << 'S';
            temp--;
        }
        temp = (int)n[2] - 48;
        a = 1;
        while(a <= temp){
            cout << a;
            a++;
        }
    }
    else if( t == 2 ){
        temp = (int)n[0] - 48;
        while(temp != 0){
            cout << 'S';
            temp--;
        }
        temp = (int)n[1] - 48;
        a = 1;
        while(a <= temp){
            cout << a;
            a++;
        }
    
    }
    else if( t == 1 ){
        temp = (int)n[0] - 48;
        a = 1;
        while(a <= temp){
            cout << a;
            a++;
        }
    }
    return 0;
}
