//
//  pat-basic-1018.cpp
//  ACM
//
//  Created by 王子豪 on 2017/7/22.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;
int main(void){
    int n;
    cin >> n;
    char A;
    char B;
    int A_sheng = 0;
    int A_fu = 0;
    int A_ping = 0;
    int B_sheng = 0;
    int B_fu = 0;
    int B_ping = 0;
    int A_C = 0;
    int A_J = 0;
    int A_B = 0;
    int B_C = 0;
    int B_J = 0;
    int B_B = 0;
    for(int i = 0;i < n;i++){
        cin >> A;
        getchar();
        cin >> B;
        if(A == 'C' && B == 'J'){
            A_sheng++;
            A_C++;
            B_fu++;
        }
        else if(A == 'C' && B == 'C'){
            A_ping++;
            B_ping++;
        }
        else if(A == 'C' && B == 'B'){
            A_fu++;
            B_sheng++;
            B_B++;
        }
        else if(A == 'J' && B == 'C'){
            A_fu++;
            B_sheng++;
            B_C++;
        }
        else if(A == 'J' && B == 'J'){
            A_ping++;
            B_ping++;
        }
        else if(A == 'J' && B == 'B'){
            A_sheng++;
            A_J++;
            B_fu++;
        }
        else if(A == 'B' && B == 'C'){
            A_sheng++;
            A_B++;
            B_fu++;
        }
        else if(A == 'B' && B == 'J'){
            A_fu++;
            B_sheng++;
            B_J++;
        }
        else if(A == 'B' && B == 'B'){
            A_ping++;
            B_ping++;
        }
    }
    cout << A_sheng << ' ' << A_ping << ' ' << A_fu << endl;
    cout << B_sheng << ' ' << B_ping << ' ' << B_fu << endl;
    if(A_C <= A_J && A_J <= A_B) cout << 'B';
    else if(A_J <= A_C && A_C <= A_B) cout << 'B';
    else if(A_B <= A_J && A_J <= A_C) cout << 'C';
    else if(A_J <= A_B && A_B <= A_C) cout << 'C';
    else if(A_B <= A_C && A_C <= A_J) cout << 'J';
    else if(A_C <= A_B && A_B <= A_J) cout << 'J';
    cout << ' ';
    if(B_C <= B_J && B_J <= B_B) cout << 'B';
    else if(B_J <= B_C && B_C <= B_B) cout << 'B';
    else if(B_B <= B_J && B_J <= B_C) cout << 'C';
    else if(B_J <= B_B && B_B <= B_C) cout << 'C';
    else if(B_B <= B_C && B_C <= B_J) cout << 'J';
    else if(B_C <= B_B && B_B <= B_J) cout << 'J';
    return 0;
}
