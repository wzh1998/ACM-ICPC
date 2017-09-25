//
//  1055.cpp
//  ACM
//
//  Created by 王子豪 on 19/06/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void){
    int n,m,T,a,Result;
    cin >> T;
    int Chang,Kuan;
    for(int i = 0;i < T;i++){
        cin >> n >> m >> a;
        if( n % a == 0 ) Chang = n / a;
        else Chang = n/a + 1;
        if( m % a == 0 ) Kuan = m / a;
        else Kuan = m / a + 1;
        Result = Chang * Kuan;
        cout << Result << endl;
    }
    return 0;
}
