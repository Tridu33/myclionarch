#include<iostream>
using namespace std;

int main(int argc,const char * argv[]){
    int groups,num,val;
    scanf("%d",&groups);
//    for(int i = 0;i<groups;i++){    }
    while(groups -- ){
        scanf("%d",&num);
        int sum = 0;
        while(num--){
            scanf("%d",&val);
            sum += val;
        }
        printf("%d\n",sum);//printf("%d\n",&sum);不能输入地址
    }
    return 0;
}
