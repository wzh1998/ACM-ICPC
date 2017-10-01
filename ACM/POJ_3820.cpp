//
//  POJ_3820.cpp
//  ACM
//
//  Created by 王子豪 on 2017/10/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

stack <string> mystack;
string test;

int current,position;
bool result = true;
bool Final_Result = true;
int name_start;
int name_end;
string tag;

bool is_text(char x){
    return (x >= 32 && x <= 127 && x != '<' && x != '>' && x != '&') ? true : false;
}
bool is_hex(char x){
    return ((x >= '0' && x <= '9') || (x >= 'a' && x <= 'f') || (x >= 'A' && x <= 'F')) ? true : false;
}
bool is_alp(char x){
    return ((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z')) ? true : false;
}

bool find(char findwhat,char findin){
    if(findwhat == 'H') return is_hex(findin);
    else if(findwhat == 'A') return is_alp(findin);
    else if(findwhat == 'T') return is_text(findin);
    else return (findwhat == findin);
}

bool truefind(string x){
    
    for(position = 0;(current + position) < test.length();position++){
        if(find(x[position],test[position + current]) == false) break;
        if(x[position] == '\0') return false;
    }
    if (x[position] != '\0')
        return false;
    else{
        current = current + position;
        return true;
    }
}

int main(void){
    
    while(1) {
        result = true;
        getline(cin,test);
        if (cin.eof()) break;
        
        current=0;
        bool slash_start = false;
        bool slash_end = false;
        while(!mystack.empty())
            mystack.pop();
        
        while(current < test.length()){
            if (truefind("T")) continue;
            else if (truefind("<")){
                slash_start = truefind("/");
                name_start = current;
                while(truefind("A"));
                name_end = current;
                tag = test.substr(name_start,name_end - name_start);
                
                //            if(tag == "") return false;
                
                if(slash_start == false) slash_end = truefind("/");//如果一开始就没找到'/',那就在tag之后找
                else slash_end = false; //如果一开始就有‘／’的话，之后就不找了
                if(truefind(">") == false){
                    result = false;
                    break;
                }
                if(slash_start == true) {
                    if(mystack.empty()){
                        result = false;
                        break;
                    }
                    if(mystack.top() != tag){
                        result = false;
                        break;
                    }
                    mystack.pop();
                }
                if(slash_start == false && slash_end == false)
                    mystack.push(tag);
            }
            else if (truefind("&")) {
                if (truefind("lt;") || truefind("gt;") || truefind("amp;")) continue;
                else if (truefind("xHH")) {
                    int t = 0;
                    for(t = 0;truefind("H");t++);
                    if ((truefind(";") && (t % 2 == 0)) == false){
                        result = false;
                        break;
                    }
                }
                else {
                    result = false;
                    break;
                }
            }
            else{
                result = false;
                break;
            }
        }
        if(result != false)
            result = mystack.empty();
        if (result) {
            cout << "valid" << endl;
        } else {
            cout << "invalid" << endl;
        }
        
    }
    return 0;
}
