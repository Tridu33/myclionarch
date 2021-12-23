#include "everything.h"
using namespace std;
int N,M,bcj[100001];
int Find(int x){
    if(bcj[x]<0) return x;
    return bcj[x]=Find(bcj[x]);
}
void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    if(x==y) return ;
    bcj[x]+=bcj[y];
    bcj[y]=x;
}
int main(){
	ios_base::sync_with_stdio(false);
    int i,x,y;
    string com;
    cin>>N>>M;
    for(i=0;i<=N;i++) bcj[i]=-1;
    for(i=1;i<=M;i++){
        cin>>com;
        if(com=="Union"){
            cin>>x>>y;
            Union(x,y);
        }
        if(com=="Find"){
            cin>>x>>y;
            if(Find(x)==Find(y)) cout<<"True"<<endl; 
            else cout<<"False"<<endl; 
        }
        if(com=="Count"){
            cin>>x; 
            cout<<0-bcj[Find(x)]<<endl;
        }
    }
    system("pause");
    return 0;
}
