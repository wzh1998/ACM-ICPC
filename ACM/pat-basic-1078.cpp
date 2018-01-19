//
//  pat-basic-1078.cpp
//  ACM
//
//  Created by 王子豪 on 2018/1/19.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>


using namespace std;
int main(void){
    
    char type;
    string current;
    cin >> type;
    getchar();
    if(type == 'C'){
        int counter = 1;
        getline(cin, current);
        char temp = current[0];
        for(int i = 1;i <= current.length();i++){
            if(current[i] == temp) counter++;
            else{
                if(counter == 1) cout << temp;
                else cout << counter << temp;
                counter = 1;
                temp = current[i];
            }
        }
    }
    else if(type == 'D'){
        getline(cin, current);
        int counter = 0;
        for(int i = 0;i <= current.length();i++){
            if(current[i] >= '0' && current[i] <= '9'){
                if(current[i + 1] >= '0' && current[i + 1] <= '9'){
                    counter += current[i] - '0';
                    counter *= 10;
                }
                else counter += current[i] - '0';
                
            }
            else{
                if(counter == 0) cout << current[i];
                else{
                    for(int j = 0;j < counter;j++) cout << current[i];
                    counter = 0;
                }
            }
        }
    }
    
    return 0;
}
