#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int a,b,x;
    int temp;
    temp = 0;
    while(1){
        cin >> a >> b;
        if(b > 0){
            if(temp == 0){
                cout << a * b << ' ' << b - 1;
                temp = 1;
            }
            else{
                cout << ' ' << a * b << ' ' << b - 1;
            }
        }
        x = getchar();
        if(x == '\n') break;
    }
    if(temp == 0){
        cout << "0 0";
    }
    
    return 0;
}
