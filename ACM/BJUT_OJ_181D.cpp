//
//  BJUT_OJ_181D.cpp
//  ACM
//
//  Created by 王子豪 on 2018/4/17.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int year_alldays(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 366;
    else return 365;
}


int year_sumday(int year,int month){
    int sum=0;
    int rui[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int ping[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int ruiflag = 0;
    if((year%4 == 0 && year % 100 != 0) || year % 400 == 0) ruiflag = 1;
    for(int index = 0;index < month - 1;index++){
        if(ruiflag == 1) sum += rui[index];
        else sum += ping[index];
    }
    return sum;
}

int get_g_alldays(int year,int month,int day)
{
    int i = 1800;
    int days = -24;
    while(i < year){
        days += year_alldays(i);
        i++;
    }
    int days2 = year_sumday(year,month);
    return days + days2 + day;
}

int main(void){
    int year1,year2,month1,month2,day1,day2;
    scanf("%d-%d-%d",&year1,&month1,&day1);
    scanf("%d-%d-%d",&year2,&month2,&day2);
    int days1 = get_g_alldays(year1,month1,day1);
    int days2 = get_g_alldays(year2,month2,day2);
    int sout = 0;
    if(days1 > days2) {
        cout << "liang qing ruo shi jiu chang shi you qi zai zhao zhao mu mu" << endl;
        return 0;
    }
    sout = days2 - days1;
    cout << sout << endl;
    
    return 0;
}
