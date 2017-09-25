//
//  pat-basic-1003.cpp
//  ACM
//
//  Created by 王子豪 on 05/07/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
using namespace std;

int main(void){
    int n,length,i,beishu;
    int counter;
    int counter2;
    int counter3;
    string x;
    cin >> n;
    for(int z = 0;z < n;z++){
        cin >> x;
        length = x.length();
        counter = 0;
        //////   1
        if(x[0] == 'P'){
            int k = 1;
            if(x[1] == 'A'){
                for(;k < length && x[k] == 'A';k++){
                    continue;
                }
                if(x[k] == 'T'){
                    cout << "YES" << endl;
                    continue;
                }
                else{
                    cout << "NO" << endl;
                    continue;
                }
            }
            else{
                cout << "NO" << endl;
                continue;
            }
        }
        
        /////    2
        else if( x[0] == 'A' ){
            i = 1;
            counter2 = 0;
            counter = 1;
            counter3 = 0;
            
            
            while(x[i] == 'A' ){
                if(i >= length){
                    cout << "NO" << endl;
                    break;
                }
                i++;
                counter++;
            }
            
            
            
            if(x[i] == 'P' && i < length){
                i++;
            }
            else{
                cout << "NO" << endl;
                continue;
            }
            

            if(x[i] == 'A' && i < length){
                while(x[i] == 'A' ){
                    if(i >= length){
                        cout << "NO" << endl;
                        break;
                    }
                    i++;
                    counter2++;
                }
            }
            else{
                cout << "NO" << endl;
                continue;
            }
            
            if(x[i] == 'T' && i < length){
                i++;
                if(x[i] == 'A'){
                    while(x[i] == 'A' && i < length){
                        i++;
                        counter3++;
                    }
                    beishu = counter3 / counter;
                    if(counter * beishu == counter3 && counter2 == beishu){
                        cout << "YES" << endl;
                        continue;
                    }
                    else{
                        cout << "NO" << endl;
                        continue;
                    }
                }
                
                else{
                    cout << "NO" << endl;
                    continue;
                }
            }
            else{
                cout << "NO" << endl;
                continue;
            }
        }
        
        else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
