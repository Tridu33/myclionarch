// #include<string>
// #include<iostream>
// #include<sstream>
// #include<vector>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<string> vec;
    scanf("%d",&n);
    while(n--){
        string str;
        cin>>str;//scanf("%s" , &str);//这样会数组越界
        vec.push_back(str);
    }
    long len = vec.size();
    sort(vec.begin(),vec.end());
    for(int i =0;i<len - 1;i++){
        cout<<vec[i]<<" ";
    }
    cout<<vec[len-1];    
    return 0;
}




















