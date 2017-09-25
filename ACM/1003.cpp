//
//  1003.cpp
//  ACM
//
//  Created by 王子豪 on 20/06/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void){
    int timer;
    
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        timer = 0;
        string x;
        cin >> x;
        for(int k = 0;x[k] != 'G';k++){
            if( x[k] == '[') timer++;
            else if( x[k] == ']') timer--;
        }
        cout << timer << endl;
    }
    return 0;
}
