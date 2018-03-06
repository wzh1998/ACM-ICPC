//
//  BJUT_OJ_lq17I.cpp
//  ACM
//
//  Created by 王子豪 on 2018/3/6.
//  Copyright © 2018年 王子豪. All rights reserved.
//

#include <iostream>
#include <regex>

using namespace std;

int main(void){
    regex reg1("^(http://)(\\d{1,5})([.])(\\d{1,5})([.])(\\d{1,5})([.])(\\d{1,5})/$");
    string s1;
    cin >> s1;
    smatch r1;
    if(regex_match(s1, r1, reg1)) cout << "Yes";
    else cout << "No";
}

