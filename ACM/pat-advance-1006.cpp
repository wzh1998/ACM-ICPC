#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef struct NAIVE{
    int hour;
    int minute;
    int second;
}NAIVE;
typedef struct identify{
    string ID;
    NAIVE time;
}identify;

int main(void){
    int n,i;
    cin >> n;
    identify first;
    identify last;
    
    first.time.hour = 23;
    first.time.minute = 59;
    first.time.second = 59;
    
    last.time.hour = 0;
    last.time.minute = 0;
    last.time.second = 0;
    
    identify current;
    for(i=0; i < n;i++){
        cin >> current.ID;
        cin >> current.time.hour;
        getchar();
        cin >> current.time.minute;
        getchar();
        cin >> current.time.second;
        
        if( current.time.hour < first.time.hour ){
            first.time.hour = current.time.hour;
            first.time.minute = current.time.minute;
            first.time.second = current.time.second;
            first.ID = current.ID;
        }
        else if(current.time.hour == first.time.hour){
            if(current.time.minute < first.time.minute){
                first.time.minute = current.time.minute;
                first.time.second = current.time.second;
                first.ID = current.ID;
            }
            else if(current.time.minute == last.time.minute){
                if(current.time.second < first.time.second){
                    first.time.second = current.time.second;
                    first.ID = current.ID;
                }
            }
        }
        getchar();
        cin >> current.time.hour;
        getchar();
        cin >> current.time.minute;
        getchar();
        cin >> current.time.second;
        
        if( current.time.hour > last.time.hour ){
            last.time.hour = current.time.hour;
            last.time.minute = current.time.minute;
            last.time.second = current.time.second;
            last.ID = current.ID;
        }
        else if(current.time.hour == last.time.hour){
            if(current.time.minute > last.time.minute){
                last.time.minute = current.time.minute;
                last.time.second = current.time.second;
                last.ID = current.ID;
            }
            else if(current.time.minute == last.time.minute){
                if(current.time.second > last.time.second){
                    last.time.second = current.time.second;
                    last.ID = current.ID;
                }
            }
        }
        
    }
    cout << first.ID << ' ' << last.ID;
    
    return 0;
}
