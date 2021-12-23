#include<bits/stdc++.h>
using namespace std;

int main(int argc,const char * argv[]){
    int groups,num,val;
    cin>>groups;
    while(groups -- ){
        cin>>num;
        int sum = 0;
        while(num--){
            cin>>val;
            sum += val;
        }
        cout<<sum<<endl;
    }
    return 0;
}
