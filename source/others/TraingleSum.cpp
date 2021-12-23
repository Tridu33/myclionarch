#include "bits/stdc++.h"
using namespace std;

int main(){
    int groups,x,sum;
    cin >> groups;
    for (int i = 1; i <= groups;i++){
        sum = 0;
        cin >> x;
        for (int j = 1; j <= x;j++){
            sum += j * (j + 1)*(j + 2) / 2;
        }
        cout << i << ' ' << x << ' ' << sum <<endl;
    }
    return 0;
}















