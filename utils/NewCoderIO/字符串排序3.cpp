#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    while(getline(cin,line)){
        istringstream iss(line);
        vector<string> strs;
        string s;
        while(getline(iss,s,',')){
            strs.push_back(s);
        }
        sort(strs.begin(),strs.end());
        int n = strs.size();
        for(int i =0;i<n;i++){
            if(i != 0){
                cout << "," << strs[i];
            }else{
                cout << strs[i];//0
            }
        }
        cout << endl;
    }
    return 0;
}














