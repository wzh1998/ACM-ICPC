//
//  pat-basic-1003.cpp
//  ACM
//
//  Created by 王子豪 on 03/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
typedef struct grade{
    char name[11];
    char id[11];
    int fenshu;
}grade;

int main(void){
    grade winner;
    grade loser;
    winner.fenshu = INT_MIN;
    loser.fenshu = INT_MAX;
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i < n;i++){
        grade x;
        scanf("%s %s %d",x.name,x.id,&x.fenshu);
        if(x.fenshu > winner.fenshu){
            strcpy(winner.name,x.name);
            strcpy(winner.id,x.id);
            winner.fenshu = x.fenshu;
        }
        if(x.fenshu < loser.fenshu){
            strcpy(loser.name,x.name);
            strcpy(loser.id,x.id);
            loser.fenshu = x.fenshu;
        }
    }
    cout << winner.name << ' ' << winner.id << endl;
    cout << loser.name << ' ' << loser.id ;
    
    return 0;
}
