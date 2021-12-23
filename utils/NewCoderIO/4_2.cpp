#include<bits/stdc++.h>
using namespace std;
int main (){
    int num;
    while(cin>>num && num!= 0){
        int sum = 0, curval;
        for(int i =0; i<num; i++){
            cin >> curval;
            sum += curval;
        }
        cout<<sum<<endl;
    }
    return 0;
}









