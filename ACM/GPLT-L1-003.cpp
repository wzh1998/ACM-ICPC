//
//  GPLT-L1-003.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/17.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int main(void){
    char x[1001];
    cin >> x;
    int a,b,c,d,e,f,g,h,i,j;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    int len;
    
    
    for(int k = 0;x[k] != '\0';k++){
        if(x[k] == '0') a++;
        else if(x[k] == '1') b++;
        else if(x[k] == '2') c++;
        else if(x[k] == '3') d++;
        else if(x[k] == '4') e++;
        else if(x[k] == '5') f++;
        else if(x[k] == '6') g++;
        else if(x[k] == '7') h++;
        else if(x[k] == '8') i++;
        else if(x[k] == '9') j++;
    }
    
    if(a != 0) cout << "0:" << a << endl;
    if(b != 0) cout << "1:" << b << endl;
    if(c != 0) cout << "2:" << c << endl;
    if(d != 0) cout << "3:" << d << endl;
    if(e != 0) cout << "4:" << e << endl;
    if(f != 0) cout << "5:" << f << endl;
    if(g != 0) cout << "6:" << g << endl;
    if(h != 0) cout << "7:" << h << endl;
    if(i != 0) cout << "8:" << i << endl;
    if(j != 0) cout << "9:" << j << endl;
    
    return 0;
}
