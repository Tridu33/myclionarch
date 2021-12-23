#include<iostream>
using namespace std;
int main(){
    int num;
    while(scanf("%d" ,&num) != EOF){
        int sum =0;
        int val;
        for(int i =0;i<num;i++){
            scanf("%d",&val);
            sum += val;
        }
        printf("%d\n",sum);
    }
    return 0;
}












