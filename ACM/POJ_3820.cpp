/*
    本题结合利用字符串读写处理以及栈的应用来实现简易XML语法是否有效的判断。
    Case1: 若当前字符为纯文字信息，继续判断之后字符。
    Case2: 若为‘<’号，利用构造好的find函数搜索‘<’号之后的’/’以及由小写字母或数字组合而成的tag字符串。
    Case3:若当前字符为‘&‘ ,利用 find函数搜索’&’之后的字符串.
    Case4：除此以外其他情况答案均为invalid。
    在所有字符判断完成后，若答案为valid，还需对使用过的栈进行是否为空的判断，若栈不为空，则答案为invalid。
 */

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
                if(slash_start == false) slash_end = truefind("/");
                else slash_end = false;
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
