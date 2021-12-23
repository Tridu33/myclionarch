#include<bits/stdc++.h>
using namespace std;
int main (){
    int num;
    while(scanf("%d",&num) && num!= 0){
        int sum = 0, curval;
        for(int i =0; i<num; i++){
            scanf("%d",&curval);
            sum += curval;
        };
        printf("%d\n",sum);
    }
    return 0;
}









