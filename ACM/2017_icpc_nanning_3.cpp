//
//  2017_icpc_nanning_3.cpp
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
    int pay[10000];
    memset(pay,0,sizeof(pay));
    int chanpin;
    int ren;
    int id = 0;
    cin >> chanpin >> ren;
    for(int i = 0;i < chanpin;i++){

        double final_p = 0;
        int base = 0;
        double first_price = 0;
        double second_price = 0;
        int first_person = 0;
        int second_person = 0;
        id = 0;
        int price = 0;
        scanf("%d %d",&base,&id);
        while(id != -1){
            scanf("%d",&price);
            if(price >= base){
                if(price >= first_price){
                    if(price > first_price || (price == first_price && id < first_person)){
                        second_price = first_price;
                        second_person = first_person;
                        first_price = price;
                        first_person = id;
                    }
                }
                if(price > second_price && price < first_price){
                    second_price = price;
                    second_person = id;
                }
            }
            scanf("%d",&id);
        }
        if(second_price == 0 && first_price != 0){
            second_price = base;
        }
        final_p = min(first_price,floor(1.10 * second_price));
        pay[first_person] += final_p;
    }
    int question;
    scanf("%d",&question);
    for(int i = 0;i < question;i++){
        scanf("%d",&id);
        printf("%d\n",pay[id]);
    }

    return 0;
}
