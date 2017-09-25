//
//  pat-basic-1067.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/25.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
int main(void){
    int time;
    char password[300];
    memset(password, '\0', sizeof(password));
    
    char temp[200];
    memset(temp, '\0', sizeof(temp));
    int N;
    
    cin >> password >> N;
    bool iftrue = false;
    getchar();
    for(int i = 0;i < N;i++){
        memset(temp, '\0', sizeof(temp));
        scanf("%200[^\n]",temp);
        if(strcmp(temp,"#")==0) return 0;
        if(strcmp(temp,password)==0){
            cout << "Welcome in" << endl;
            //            iftrue = true;
            return 0;
        }
        else{
            cout << "Wrong password: " << temp << endl;
        }
        getchar();
    }
    //    if(iftrue == false)
    cout << "Account locked" << endl;
    
    return 0;
}
