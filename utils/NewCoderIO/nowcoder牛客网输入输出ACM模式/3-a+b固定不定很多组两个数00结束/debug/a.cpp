#include <stdio.h>
int main()
{
int a,b;
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
freopen("out.txt","w",stderr);
while(1) {
scanf("%d%d",&a,&b);
if (a==0&&b==0) break;
printf("%d\n",a+b);
}
fclose(stdin);
fclose(stdout);
fclose(stderr);
return 0;
}