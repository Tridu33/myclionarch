#include<iostream>
using namespace std;
int main(){
    int num;
    while(cin>>num){
        int sum =0;
        int val;
        for(int i =0;i<num;i++){
            cin>>val;
            sum += val;
        }
        cout << sum << endl;
    }
    return 0;
}












