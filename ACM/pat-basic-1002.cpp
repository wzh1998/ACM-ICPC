//
//  pat-basic-1002.cpp
//  ACM
//
//  Created by 王子豪 on 03/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <stdio.h>
int main(void){
    int result = 0;
    char result2[5000] = {'\0'};
    int c;
    c = getchar();
    while(c != '\n'){
        result += c - 48;
        c = getchar();
    }
    sprintf(result2,"%d",result);
    for(int i = 0;result2[i] != '\0';i++){
        if(result2[i] == '0') printf("ling");
        else if(result2[i] == '1') printf("yi");
        else if(result2[i] == '2') printf("er");
        else if(result2[i] == '3') printf("san");
        else if(result2[i] == '4') printf("si");
        else if(result2[i] == '5') printf("wu");
        else if(result2[i] == '6') printf("liu");
        else if(result2[i] == '7') printf("qi");
        else if(result2[i] == '8') printf("ba");
        else if(result2[i] == '9') printf("jiu");
        if(result2[i+1] != '\0')printf(" ");
    }
    return 0;
}
