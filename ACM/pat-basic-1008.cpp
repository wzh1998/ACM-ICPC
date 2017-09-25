#include <iostream>
using namespace std;

int main(void){
    int n,m,i,temp;
    cin >> n >> m;
    int array[n];
    int result[n];
    
    for(i = 0;i < n;i++){
        cin >> array[i];
    }
    for(i = 0;i < n;i++){
        temp = i + m;
        temp %= n;
        result[temp] = array[i];
    }
    i = 0;
    for(i = 0;i < n - 1;i++){
        cout << result[i] << ' ';
    }
    cout << result[i];
}
