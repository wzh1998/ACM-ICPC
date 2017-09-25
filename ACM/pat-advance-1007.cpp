#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int main(void){
    int len;
    int f_start, f_end, sum, sumhere, start, end;
    int a[100000];
    int i;
    cin >> len;
    
    for(i = 0;i < len;i++){
        cin >> a[i];
    }
    
    sum = 0;
    f_start = 0;
    f_end = len - 1;
    sumhere = 0;
    start = 0;
    end = 0;
    for(i = 0; i < len; i ++){
        if(sumhere >= 0){
            sumhere += a[i];
            end = i;
        }
        else{
            sumhere = a[i];
            start = i;
            end = i;
        }
        if(sumhere > sum || (sumhere == 0 && f_end == len - 1)){
            sum = sumhere;
            f_start = start;
            f_end = end;
        }
    }
    printf("%d %d %d\n", sum, a[f_start], a[f_end]);
    
    return 0;
}
