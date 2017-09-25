
//
//  1053.cpp
//  ACM
//
//  Created by 王子豪 on 19/06/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void){
    int T;
    long long int a,b,n,fib,left,right;
    cin >> T;
    for(int i = 0;i < T;i++){
        cin >> a >> b >> n;
        if( n == 0) cout << a << endl;
        else if(n == 1) cout << b << endl;
        else{
        left = a;
        right = b;
        for(int i = 0;i < n-1;i++){
            left %= 1000000007;
            right %= 1000000007;
            fib = left + right;
            fib %= 1000000007;
            left = right;
            right = fib;
        }
        cout << fib << endl;
        }
    }
        
    return 0;
}
