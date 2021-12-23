#include<string>
// #include<sstream>
// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    while(getline(cin,input) ){
        istringstream iss(input);
        int sum = 0,val;
        while(iss >> val){
            sum += val;
        }
        cout<<sum<<endl;
    }
    return 0;
}











