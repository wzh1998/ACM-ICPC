//
//  2017_icpc_qd.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/20.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void){
    int T;
    char arr[12][10] = {{'r','a','t'},{'o','x'},{'t','i','g','e','r'},{'r','a','b','b','i','t'},{'d','r','a','g','o','n'},{'s','n','a','k','e'},{'h','o','r','s','e'},{'s','h','e','e','p'},{'m','o','n','k','e','y'},{'r','o','o','s','t','e','r'},{'d','o','g'},{'p','i','g'}};
    cin >> T;
    for(int i = 0;i < T;i++){
        char temp[10];
        memset(temp,'\0',sizeof(temp));
        char sign_wife[10];
        char sign_hus[10];
        memset(sign_hus, '\0', sizeof(sign_hus));
        memset(sign_wife,'\0',sizeof(sign_wife));
        cin >> sign_wife;
        cin >> sign_hus;
        bool status_wife = false;
        bool status_hus = false;
        int index_wife = 0;
        int index_hus = 0;
        
        for(int i = 0;i < 12 && (status_wife != true || status_hus != true);i++){
            if((status_wife != true)&&(strcmp(arr[i],sign_wife) == 0)){
                status_wife = true;
                index_wife = i + 1;
            }
            if((status_hus != true)&&(strcmp(arr[i],sign_hus) == 0)){
                status_hus = true;
                index_hus = i + 1;
            }
        }
        if(index_wife < index_hus){
            cout << index_hus - index_wife << endl;
        }
        else if(index_wife == index_hus) cout << 12 << endl;
        else cout << 12 - (index_wife - index_hus) << endl;
        
    }
    
    return 0;
}

