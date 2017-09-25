//
//  pat-advance-1001.cpp
//  ACM
//
//  Created by 王子豪 on 04/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;

int main(void){
    int a;
    int b;
    string result;
    cin >> a >> b;
    result = to_string(a + b);
    int length ;
    length = result.length();
//    cout << '<' << length << '>' << endl;
//    cout << '<' << result << '>';
    if(result[0] == '-'){
        length = length - 1;
        int timer = length % 3;
        cout << '-';
        length += 1;
        for(int i = 1;i < length;i++){
            if( timer == 0 ) {
                timer = 3;
                if( i != length - 1 && i != 1) cout << ',';
            }
            
            cout << result[i];
            timer--;
        }
    }
    else{
        int  timer = length % 3;
        for(int i = 0;i < length;i++){
            if( timer == 0 && i != length - 1 && i != 0) {
                cout << ',';
                timer = 3;
            }
            cout << result[i];
            timer--;
        }
    }
    return 0;
}
