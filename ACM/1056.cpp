//
//  1056.cpp
//  ACM
//
//  Created by 王子豪 on 20/06/2017.
//  Copyright © 2017 王子豪. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void){
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        int M,N,X,Y;
        cin >> M >> N >> X >> Y;
        int arr[M][N];
        int temp = 1;
        int t = 0;
        int left = 0;
        int right = 0;
        int up = 0;
        int down = 0;
        if ( M == 1 && N == 1) cout << "1" << endl;
        else{
            while( temp <= M * N){
                if(temp <= M * N){
                    for(int a = M - down - 1; a >= up;a--){
                        arr[a][t] = temp;
                        temp++;
                        if( temp > M * N) break;
                    }
                    left++;
                }
                if(temp <= M * N){
                    for(int b = left; b <= N - right - 1;b++){
                        arr[t][b] = temp;
                        temp++;
                        if( temp > M * N) break;
                    }
                    up++;
                }
                if(temp <= M * N){
                    for(int c = up; c <= M - down - 1; c++){
                        arr[c][N - t - 1] = temp;
                        temp++;
                        if( temp > M * N) break;
                    }
                    right++;
                }
                if(temp <= M * N){
                    for(int d = N - right - 1;d >= left;d--){
                        arr[M - t - 1][d] = temp;
                        temp++;
                        if( temp > M * N) break;
                    }
                    down++;
                }
                    t++;
            }
            for(int i = 0;i < M;i++){
                for(int k = 0;k < N;k++){
                    cout << "   " << arr[i][k];
                }
                cout << endl;
            }
            cout << arr[X-1][Y-1] << endl;
        }
    }
    return 0;
}
