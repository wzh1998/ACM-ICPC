//
//  pat-basic-1011.cpp
//  ACM
//
//  Created by 王子豪 on 12/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void){
    long long int A;
    long long int B;
    long long int C;
    int n;
    cin >> n;
    
    
    
    for(int i = 0;i < n;i++){
        cin >> A >> B >> C;
        if(A + B > C)
            cout << "Case #" << i + 1 << ": true" << endl;
        else
            cout << "Case #" << i + 1 << ": false" << endl;
        
    }
    
    return 0;
}
