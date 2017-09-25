#include <stdio.h>
#include <iostream>

using namespace std;

int ny_day(int year,int month,int date){
    
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        if(month <= 2 && date < 29) return 366;
        
        else return 365;
    }
    else if(((year + 1) % 4 == 0 && (year + 1) % 100 != 0) || ((year + 1) % 400 == 0)){
        if(month >= 3) return 366;
        else return 365;
    }
    else return 365;
}
int main(void){
    int year;
    int month;
    int date;
    int n;
    int i;
    int temp;
    int count_y;
    cin >> n;
    for(i = 0;i < n;i++){
        cin >> year >> month >> date;
        if(month == 2 && date == 29){
            cout << year + 28 << endl;
            continue;
        }
        temp = 0;
        count_y = 0;
        do{
            temp += ny_day(year,month,date);
            year++;
            count_y++;
        }while(temp % 7 != 0);
        cout << year << endl;
    }
    
    return 0;
}
