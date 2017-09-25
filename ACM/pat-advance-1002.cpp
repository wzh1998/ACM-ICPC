//
//  pat-advance-1002.cpp
//  ACM
//
//  Created by 王子豪 on 04/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(void){
    int n1;
    int n2;
    
    cin >> n1;
    int N1[n1];
    double aN1[n1];
    for(int i = 0;i < n1;i++){
        cin >> N1[i];
        cin >> aN1[i];
       
    }
    
    cin >> n2;
    int N2[n2];
    double aN2[n2];
    for(int k = 0;k < n2;k++){
        cin >> N2[k];
        cin >> aN2[k];
    }
    int r_N[100] = {-1};
    double r_aN[100] = {-1.0};
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    while(1){
        if(index1 == n1 || index2 == n2){
            if(index1 == n1 ){
                for(;index2 < n2;index2++){
                    r_N[index3] = N2[index2];
                    r_aN[index3] = aN2[index2];
                    index3++;
                }
                break;
            }
            else if(index2 == n2 ){
                for(;index1 < n1;index1++){
                    r_N[index3] = N1[index1];
                    r_aN[index3] = aN1[index1];
                    index3++;
                }
                break;
            }
        }
        if(N1[index1] == 0 && N2[index2] == 0){
            r_N[index3] = 0;
            r_aN[index3] = aN1[index1] + aN2[index2];
            index3++;
            break;
        }
        else if(N1[index1] == N2[index2]){
            r_N[index3] = N1[index1];
            r_aN[index3] = aN1[index1] + aN2[index2];
            index1++;
            index2++;
            index3++;
        }
        else if(N1[index1] > N2[index2]){
            r_N[index3] = N1[index1];
            r_aN[index3] = aN1[index1];
            index1++;
            index3++;
        }
        else if(N1[index1] < N2[index2]){
            r_N[index3] = N2[index2];
            r_aN[index3] = aN2[index2];
            index2++;
            index3++;
        }
    }
    int i;
    for(i = 0;i < n1;i++){
        if(aN1[i] == 0.0)
            index3--;
    }
    for(i = 0;i < n2;i++){
        if(aN2[i] == 0.0)
            index3--;
    }
    cout << index3 << ' ';
    int z = 0;
    for(z = 0;z < index3 - 1;z++){
        if(r_aN[z] != 0.0){
            printf("%d ",r_N[z]);
            printf("%.1lf ",r_aN[z]);
        }
    }
    if(r_aN[z] != 0.0){
        printf("%d ",r_N[z]);
        printf("%.1lf",r_aN[z]);
    }
    return 0;
}
