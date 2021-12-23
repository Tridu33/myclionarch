#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        istringstream iss(line);
        string str;
        vector<string> vec;
        while(iss >> str){
            vec.push_back(str);
        }
        sort(vec.begin(),vec.end());
        unsigned long length = vec.size();
        for(int i =0;i < length - 1; i++){
            cout<< vec[i] << ' ';
        }
        cout << vec[length - 1] << endl;
    }
    return 0;
}













