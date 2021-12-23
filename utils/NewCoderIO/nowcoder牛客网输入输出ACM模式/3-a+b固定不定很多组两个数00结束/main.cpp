#include <stdio.h>
int main(){
    int a,b;
    while(1) {
    scanf("%d%d",&a,&b);
    if(a==0&&b==0) break;
    printf("%d\n",a+b);
    }
    return 0;
}

/*

>.\a.exe
1 2
3
3 4
7
5 6
11
0 0

*/