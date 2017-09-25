#include <iostream>
using namespace std;

int main(void){
    int number;
    string current;
    cin >> number;
    for(int i = 0;i < number;i++){
        cin >> current;
        int k = (int)current.length();
        if(k < 10) cout << current << endl;
        else cout << current[0] << k-2 << current[k - 1] << endl;
    }
}
